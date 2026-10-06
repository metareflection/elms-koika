# When are two staged functions the same function?

Stage the same helper at two call sites:

```scala
def twice(n: Rep[Int]): Rep[Int] = n * unit(2)
def snippet(x: Rep[Int]): Rep[Int] = fun(twice)(x) + fun(twice)(x + unit(1))
```

and, before `DedupFunctions`, you got two of it:

```scala
def snippet(x0: Int): Int = {
  val x5 = x1(x0)
  val x11 = x0 + 1
  val x12 = x6(x11)
  x5 + x12
}
def x6(x7: Int): Int = x7 * 2
def x1(x2: Int): Int = x2 * 2
```

`x1` and `x6` are the same function under two names. Both get emitted, both get
compiled, and the only cost is size, so this was never a correctness bug. It is
still worth understanding, because the reason it happens is the reason a
different and load-bearing thing works.

## The memo is for recursion

`Driver.makeFun` keeps a table:

```scala
val key = canonicalize(f.asInstanceOf[Serializable])
funTable.get(key) match {
  case Some(symb) => unsafeWrap(symb)
  case None       => { /* allocate a name, register it, then fill the body */ }
}
```

Note the order. The name goes into `funTable` *before* `stub.fill` runs the
closure. That ordering is the whole point: a recursive function is written

```scala
def fact: Rep[Int => Int] = fun { (n: Rep[Int]) =>
  if n === unit(0) then unit(1) else n * fact(n - unit(1))
}
```

so staging the body re-enters `fun` with the same closure: same lambda class,
same captures, same key. The memo is what turns that re-entry into a reference
to the function currently being built rather than an infinite regress, and it
is why the staged `fact` calls itself:

```scala
def x1(x2: Int): Int = {
  val x4 = x2 == 0
  if x4 then 1 else { val x9 = x1(x2 - 1); x2 * x9 }
}
```

Deduplicating two *different* call sites is a thing the memo looks like it
should do. It never could.

## Why the key cannot see two call sites as one

`canonicalize` serializes the closure:

```scala
def canonicalize(f: Serializable): String = {
  val s = new java.io.ByteArrayOutputStream()
  val o = new java.io.ObjectOutputStream(s)
  o.writeObject(f)
  Base64.getEncoder.encodeToString(s.toByteArray)
}
```

`ClosureCompare extends Externalizable` with a `writeExternal` that writes
nothing, which is the trick that makes this work at all: the closure captures
the driver, and the driver serializing to zero bytes means two closures over the
same driver are not distinguished by their captured state.

What they *are* distinguished by is their own class. `fun(twice)` at two source
sites is two eta-expansions, which is two lambda classes, which is two
serialized forms. Measured, five closures give five keys:

```
eta twice #1   equal to: eta twice #1
eta twice #2   equal to: eta twice #2
eta thrice     equal to: eta thrice
lambda 2x #1   equal to: lambda 2x #1
lambda 2x #2   equal to: lambda 2x #2
distinct keys: 5 of 5
```

Two eta-expansions of the same method are as different to the key as two
unrelated methods. So the memo matches exactly when the same closure *object*
comes back, and that is the recursive case and nothing else.

One consequence worth knowing when writing a DSL program: binding the closure
once does dedupe, because then there really is one object.

```scala
val f = fun((n: Rep[Int]) => n * unit(2))
f(x) + f(x + unit(1))          // one function, two calls
```

## LMS has the same limit

This is inherited rather than invented. lms-clean's `__fun` is the same three
lines:

```scala
val can = canonicalize(f)
Adapter.funTable.find(_._2 == can) match {
  case Some((funSym, _)) => funSym
  case _ => /* ... */
}
```

and its `ClosureCompare` is the same `Externalizable` with the same empty
`writeExternal`, differing from ours only in `toString("ASCII")` where ELMS uses
Base64. Its comment is explicit that the memo exists for re-entry:

> recursive functions have to be written as `lazy val f = fun{...}` or
> `def f = fun{...}`, in which case the recursive calls will re-enter the `fun`
> call

Compiling lms-clean's own `ClosureCompare` under Scala 2.12 and running the same
five closures through it gives the same `distinct keys: 5 of 5`. Original LMS's
`FunctionsExp.doLambda` does not attempt the memo at all and carries a `TODO:
this will not work if f is recursive`.

So the behaviour is not a Scala 3 artefact and not an ELMS mistake. It is what
this mechanism does.

## Comparing the output instead

`elms.pipeline.DedupFunctions` runs from `Driver.extract`, so it covers every
driver and both builders. It ignores how a function was spelled and looks at
what came out: renumber each function's bound names by position, group by the
result, keep one per group, and rewrite calls to the ones dropped.

That catches the two-call-sites case, and it also catches a case the key could
never reach, which is two differently-written closures that happen to build the
same body.

Two details it has to get right.

**A function's own name is free in its body.** `Function` carries its argument
and body but not its name, so a recursive function and a copy of it differ in
exactly one place: the name each one calls. Canonicalisation binds the name
alongside the argument, and the two then compare equal.

**One merge can create another.** Two callers are only equal once the two names
they call have become one, so a single pass is not enough. `settle` repeats the
merge until a round finds nothing.

## What it does not do

It does not deduplicate anything but top-level functions, and it compares whole
bodies, so two functions that differ in one constant stay two. Common
subexpression elimination across function bodies is a different job and the
e-graph pipeline is where it would belong.

It also does not make the closure key any better, because nothing can. The
lambda's identity is the only handle on its code, and two source sites are two
lambdas in Scala 2 and Scala 3 alike.
