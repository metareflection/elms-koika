#include <stdbool.h>

int snippet(int x0);
int gauss(int x1, int x2);
int snippet(int x0) {
  int x10 = 0;
  int x11 = gauss(x0, x10);
  return x11;
}

int gauss(int x1, int x2) {
  int x3 = 0;
  bool x4 = x1 <= x3;
  int x9;
  if (x4) {
    x9 = x2;
  } else {
    int x5 = 1;
    int x6 = x1 - x5;
    int x7 = x2 + x1;
    int x8 = gauss(x6, x7);
    x9 = x8;
  }
  return x9;
}

