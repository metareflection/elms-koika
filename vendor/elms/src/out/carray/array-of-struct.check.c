#include "elms_lib.h"

ELMS_ARR_DECL(elms_arr_Box, struct Box *)

struct Box {
  int * xs;
  int n;
};

int snippet(int x0);
int snippet(int x0) {
  elms_arr_Box x1 = elms_arr_Box_new(x0);
  int x2 = x1.len;
  return x2;
}

