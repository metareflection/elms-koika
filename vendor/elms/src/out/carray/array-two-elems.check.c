#include <stdlib.h>
#include "elms_lib.h"

ELMS_ARR_DECL(elms_arr_int, int)

int snippet(int x0);
int snippet(int x0) {
  elms_arr_int x1 = elms_arr_int_new(x0);
  char * x2 = (char *)malloc(sizeof(char) * x0);
  int x3 = 0;
  char x4 = 'z';
  x2[x3] = x4;
  int x6 = x1.len;
  return x6;
}

