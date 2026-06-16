#!/usr/bin/env python3

import argparse
import os
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

DRY_RUN = False

REPO_URL = "git@github.com:metareflection/elms"
BRANCH = "main"
SRC_SUBDIR = "."
DEST_DIR = "vendor/elms"

DEPENDENCY_NAME = ""

def run(args, **kwargs):
    if DRY_RUN:
        print("[dry-run] ", " ".join(map(str, args)))
        return
    kwargs["check"] = True
    subprocess.run(args, **kwargs)


def capture(args, readonly=False, **kwargs):
    kwargs["capture_output"] = True
    kwargs["text"] = True

    if not readonly and DRY_RUN:
        return 0, "[dry run, no output]"

    try:
        p = subprocess.run(args, **kwargs)
        return p.returncode, p.stdout
    except FileNotFoundError:
        return 127, ""


def dependency_name() -> str:
    if DEPENDENCY_NAME:
        return DEPENDENCY_NAME
    name = REPO_URL.rstrip("/").rsplit("/", 1)[-1].rsplit(":", 1)[-1]
    if name.endswith(".git"):
        name = name[:-4]
    return name or "dependency"


def detect_repo():
    code, out = capture(["jj", "root"], readonly=True)
    if code == 0:
        return "jj", Path(out.strip())
    code, out = capture(["git", "rev-parse", "--show-toplevel"], readonly=True)
    if code == 0:
        return "git", Path(out.strip())
    return None, None


def list_vendored_files(clone_root: Path, subdir: str) -> list[str]:
    code, out = capture(
        ["git", "-C", str(clone_root), "ls-files", "-z",
         "--cached", "--others", "--exclude-standard", "--", subdir],
        readonly=True
    )
    if code != 0:
        sys.exit(f"error: 'git ls-files' failed in the upstream clone (exit {code})")
    return [x for x in out.split("\0") if x]


def vendor_files(dest: Path) -> None:
    """Clone upstream and copy its working tree into `dest` (replacing it)."""
    with tempfile.TemporaryDirectory() as tmp:
        clone_root = Path(tmp) / "src"

        print(f"Cloning {REPO_URL} ({BRANCH}) ...")
        run(["git", "clone", "--depth", "1", "--branch", BRANCH,
             "--single-branch", REPO_URL, str(clone_root)])

        if not (clone_root / SRC_SUBDIR).is_dir():
            if DRY_RUN:
                return
            else:
                sys.exit(f"error: source subpath '{SRC_SUBDIR}' not found in upstream repo")

        print(f"Replacing {dest} ...")
        if dest.exists():
            shutil.rmtree(dest)
        dest.mkdir(parents=True, exist_ok=True)

        for f in list_vendored_files(clone_root, SRC_SUBDIR):
            rel = Path(f) if SRC_SUBDIR == "." else Path(f).relative_to(SRC_SUBDIR)
            target = dest / rel
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(clone_root / f, target)  # copy2 preserves mode + mtime


def jj_change_is_empty() -> bool:
    # `jj log` snapshots the working copy first, so this reflects the copy.
    _, out = capture(["jj", "log", "--no-graph", "-r", "@", "-T", "empty"], readonly=True)
    return out.strip() == "true"


def commit_jj(dest: Path, message: str) -> None:
    # Create the new change *before* copying, then describe only if non-empty.
    if not jj_change_is_empty():
        run(["jj", "new"])
    vendor_files(dest)
    if jj_change_is_empty():
        print("No changes from upstream; new change left empty and undescribed.")
    else:
        run(["jj", "describe", "-m", message])
        print(f"Recorded jj change: {message!r}")


def git_is_dirty() -> bool:
    _, out = capture(["git", "status", "--porcelain"], readonly=True)
    return any(line and not line.startswith("??") for line in out.splitlines())


def commit_git(dest: Path, message: str, allow_stash: bool) -> None:
    stashed = False
    if git_is_dirty() and allow_stash:
        run(["git", "stash", "push", "-m", "update_vendor.py: auto-stash"])
        stashed = True

    vendor_files(dest)

    run(["git", "add", "-A", "--", str(dest)])
    staged, _ = capture(["git", "diff", "--cached", "--quiet"], readonly=True)
    if staged == 0:
        print("No changes from upstream; nothing to commit.")
    else:
        run(["git", "commit", "-m", message])
        print(f"Committed: {message!r}")

    if stashed:
        code, _ = capture(["git", "stash", "pop"])
        if code == 0:
            print("Restored stashed changes.")
        else:
            print("warning: could not auto-restore the stash; it is still in "
                  "`git stash list` — resolve it manually.", file=sys.stderr)


def parse_args():
    p = argparse.ArgumentParser(description="Update a vendored dependency from upstream.")
    p.add_argument("--no_commit", action="store_true",
                   help="leave the surrounding jj or git repo dirty to be committed manually")
    p.add_argument("--stash", action="store_true",
                   help="in a git repo, stash a dirty tree instead of refusing "
                        "(only meaningful with --commit)")
    p.add_argument("--dry-run", action="store_true",
                   help="print the actions that would be taken; write nothing "
                        "(no clone, no copy, no commit)")
    return p.parse_args()


def main() -> int:
    global DRY_RUN
    args = parse_args()
    DRY_RUN = args.dry_run

    kind, root = detect_repo()

    if root is not None:
        os.chdir(root)             # move to the repo root before acting
        dest = root / DEST_DIR
    else:
        dest = Path.cwd() / DEST_DIR

    if DRY_RUN:
        where = f"{kind} repository at {root}" if root else "no repository (plain directory)"
        print(f"[dry-run] detected: {where}")

    if args.no_commit:
        vendor_files(dest)
        print("[dry-run] would copy files only." if DRY_RUN else "Done.")
        return 0

    message = f"updated {dependency_name()} from upstream"

    if kind == "jj":
        commit_jj(dest, message)
    elif kind == "git":
        commit_git(dest, message, allow_stash=args.stash)
    else:
        vendor_files(dest)
        if DRY_RUN:
            print("[dry-run] not a git or jj repository; done")
        else:
            print("Not a git or jj repository; done")
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except subprocess.CalledProcessError as e:
        sys.exit(f"error: command failed ({e.returncode}): {' '.join(map(str, e.cmd))}")
