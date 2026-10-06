#include "elms_lib.h"

ELMS_ARR_DECL(elms_arr_int, int)

int snippet(int x0);
int x5(elms_arr_int x6);
int snippet(int x0) {
  elms_arr_int x1 = elms_arr_int_new(x0);
  int x2 = 0;
  int x3 = 9;
  x1.data[x2] = x3;
  int x8 = x5(x1);
  int x9 = 0;
  int x10 = x1.data[x9];
  int x11 = x8 + x10;
  return x11;
}

int x5(elms_arr_int x6) {
  int x7 = x6.len;
  return x7;
}

