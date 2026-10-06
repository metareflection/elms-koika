#include <stdbool.h>

int snippet(int x0);
int snippet(int x0) {
  int x1 = x0 + x0;
  //@ assert x1 >= 0;
  int x3 = 1;
  bool x4 = x1 == x3;
  //@ assert x1 != 1;
  int x7;
  if (x4) {
    int x5 = 1;
    x7 = x5;
  } else {
    int x6 = 0;
    x7 = x6;
  }
  return x7;
}

