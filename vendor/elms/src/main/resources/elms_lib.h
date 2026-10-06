/* Definitions the ELMS C backend generates references to.
 *
 * Everything here is defined unconditionally. `CCodegen.Options` decides what
 * the generator reaches for; this file does not know and does not care. */
#ifndef ELMS_LIB_H
#define ELMS_LIB_H

/* The helpers below allocate and compare, so the header that needs these asks
 * for them rather than leaning on whatever includes it. */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* A half-open interval that outlived the `foreach` it was written for. */
typedef struct { int start; int end; } elms_range;

static inline elms_range elms_range_mk(int start, int end) {
  elms_range r = { start, end };
  return r;
}

/* An array that carries its length, declared once per element type because C
 * has no generics. The generated file writes one `ELMS_ARR_DECL` per element
 * type it uses, since a vendored header cannot know what a program allocates.
 *
 * The struct does not own `data`. Nothing generated ever calls `free`, which is
 * what a bare `malloc`ed pointer already did, but wrapping it in a struct makes
 * it look more owned than it is. */
#define ELMS_ARR_DECL(NAME, T)                                    \
  typedef struct { T * data; int len; } NAME;                     \
  static inline NAME NAME##_new(int n) {                          \
    NAME a;                                                       \
    a.data = (T *)malloc(sizeof(T) * n);                          \
    a.len = n;                                                    \
    return a;                                                     \
  }                                                               \
  static inline NAME NAME##_zero(void) {                          \
    NAME a;                                                       \
    a.data = NULL;                                                \
    a.len = 0;                                                    \
    return a;                                                     \
  }

/* Slices of `s`, clamped the way Scala's `drop`, `take` and `slice` clamp. C
 * would otherwise index outside the string for a negative or oversized bound,
 * and agreeing with the Scala backend is what makes the two comparable.
 *
 * Every clamp runs in `size_t` and nothing narrows a length to `int` on the way.
 * `(int)strlen(s)` is implementation-defined past 2GB and wraps negative in
 * practice, which turns `if (n > len) n = len` into a clamp that assigns a
 * negative bound and hands back a pointer before `s`.
 *
 * Nothing here owns `s`. `elms_str_take` and `elms_str_substring` allocate and
 * the caller frees, which nothing generated currently does. */

static inline const char * elms_str_drop(const char * s, int n) {
  size_t len = strlen(s);
  size_t k = n < 0 ? 0 : (size_t)n;
  return s + (k > len ? len : k);
}

static inline bool elms_str_startswith(const char * s, const char * p) {
  return strncmp(s, p, strlen(p)) == 0;
}

static inline bool elms_str_endswith(const char * s, const char * p) {
  size_t sl = strlen(s), pl = strlen(p);
  return sl >= pl && memcmp(s + sl - pl, p, pl) == 0;
}

/* `a` is clamped from above as well as below, which Scala's `slice` does not
 * appear to need: `"hello".slice(99, 3)` is the empty string either way. It is
 * `s + a` that needs it, since forming a pointer that far past the end is
 * undefined even when the copy that follows is zero bytes long. */
static inline char * elms_str_substring(const char * s, int a, int b) {
  size_t len = strlen(s);
  size_t lo = a < 0 ? 0 : (size_t)a;
  size_t hi = b < 0 ? 0 : (size_t)b;
  if (lo > len) lo = len;
  if (hi > len) hi = len;
  if (hi < lo) hi = lo;
  char * r = (char *)malloc(hi - lo + 1);
  memcpy(r, s + lo, hi - lo);
  r[hi - lo] = '\0';
  return r;
}

static inline char * elms_str_take(const char * s, int n) {
  return elms_str_substring(s, 0, n);
}

#endif /* ELMS_LIB_H */
