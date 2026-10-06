#include "elms_lib.h"

ELMS_ARR_DECL(elms_arr_int, int)

struct Box {
  elms_arr_int xs;
  int n;
};

int snippet(struct Box * x0);
int snippet(struct Box * x0) {
  elms_arr_int x1 = x0->xs;
  int x2 = x1.len;
  return x2;
}

