#include "elms_lib.h"

ELMS_ARR_DECL(elms_arr_int, int)
ELMS_ARR_DECL(elms_arr_arr_int, elms_arr_int)

int snippet(int x0);
int snippet(int x0) {
  elms_arr_arr_int x1 = elms_arr_arr_int_new(x0);
  int x2 = 0;
  elms_arr_int x3 = elms_arr_int_new(x0);
  x1.data[x2] = x3;
  int x5 = x1.len;
  int x6 = 0;
  elms_arr_int x7 = x1.data[x6];
  int x8 = x7.len;
  int x9 = x5 + x8;
  return x9;
}

