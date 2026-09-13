#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int snippet(int x0);
int snippet(int x0) {
  int x1 = 240;
  int x2 = x0 & x1;
  int x3 = 15;
  int x4 = x0 ^ x3;
  int x5 = x2 | x4;
  int x6 = ~x0;
  int x7 = x5 + x6;
  int x8 = 3;
  int x9 = x0 << x8;
  int x10 = x7 + x9;
  int x11 = 2;
  int x12 = x0 >> x11;
  int x13 = x10 + x12;
  int x14 = 4;
  int x15 = (int)((unsigned int)x0 >> x14);
  int x16 = x13 + x15;
  return x16;
}

