#include "elms_lib.h"

const char * snippet(const char * x0);
const char * snippet(const char * x0) {
  int x1 = 1;
  int x2 = 4;
  const char * x3 = elms_str_substring(x0, x1, x2);
  return x3;
}

