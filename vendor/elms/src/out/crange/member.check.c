#include "elms_lib.h"

struct Span {
  elms_range r;
  int tag;
};

int snippet(struct Span * x0);
int snippet(struct Span * x0) {
  elms_range x1 = x0->r;
  int x2 = x1.end;
  int x3 = x0->tag;
  int x4 = x2 + x3;
  return x4;
}

