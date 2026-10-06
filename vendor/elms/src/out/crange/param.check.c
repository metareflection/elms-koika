#include "elms_lib.h"

int snippet(elms_range x0);
int snippet(elms_range x0) {
  int x1 = 0;
  int x2 = x1;
  int x4 = x0.start;
  int x5 = x0.end;
  for (int x3 = x4; x3 < x5; x3++) {
    int x6 = x2;
    int x7 = x6 + x3;
    x2 = x7;
    /* unit */;
  }
  int x10 = x2;
  return x10;
}

