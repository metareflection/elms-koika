#include <stdbool.h>
#include "elms_lib.h"

int snippet(int x0);
int snippet(int x0) {
  int x1 = 0;
  bool x2 = x0 == x1;
  elms_range x7;
  if (x2) {
    int x3 = 0;
    elms_range x4 = elms_range_mk(x3, x0);
    x7 = x4;
  } else {
    int x5 = 10;
    elms_range x6 = elms_range_mk(x0, x5);
    x7 = x6;
  }
  int x8 = 0;
  int x9 = x8;
  int x11 = x7.start;
  int x12 = x7.end;
  for (int x10 = x11; x10 < x12; x10++) {
    int x13 = x9;
    int x14 = x13 + x10;
    x9 = x14;
    /* unit */;
  }
  int x17 = x9;
  return x17;
}

