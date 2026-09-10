#include <stdbool.h>
#include <stdlib.h>

bool snippet(int x0);
bool snippet(int x0) {
  int x1 = 0;
  bool x2 = x0 > x1;
  int x3 = 1;
  int x4 = x0 & x3;
  int x5 = 0;
  bool x6 = x4 == x5;
  bool x7 = x2 & x6;
  bool x8 = !x6;
  bool x9 = x2 ^ x8;
  bool x10 = x7 | x9;
  return x10;
}

