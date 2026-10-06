#include "elms_lib.h"

ELMS_ARR_DECL(elms_arr_int, int)

int snippet(int x0);
int snippet(int x0) {
  elms_arr_int x1 = elms_arr_int_new(x0);
  int x2 = 0;
  x1.data[x2] = x0;
  int x4 = x1.len;
  int x5 = 0;
  int x6 = x1.data[x5];
  int x7 = x4 + x6;
  return x7;
}

