#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int snippet(int x0);
int x1(int x2);
int snippet(int x0) {
  int x11 = x1(x0);
  return x11;
}

int x1(int x2) {
  int x3 = 0;
  bool x4 = x2 == x3;
  int x10;
  if (x4) {
    int x5 = 1;
    x10 = x5;
  } else {
    int x6 = 1;
    int x7 = x2 - x6;
    int x9 = x1(x7);
    x10 = x9;
  }
  return x10;
}

