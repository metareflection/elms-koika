#include <stdlib.h>
#include "elms_lib.h"

int snippet(int x0);
int snippet(int x0) {
  elms_range * x1 = (elms_range *)malloc(sizeof(elms_range) * x0);
  int x2 = 0;
  int x3 = 0;
  elms_range x4 = elms_range_mk(x3, x0);
  x1[x2] = x4;
  int x6 = 0;
  elms_range x7 = x1[x6];
  int x8 = x7.end;
  return x8;
}

