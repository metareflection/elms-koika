#include <stdlib.h>
#include <string.h>

static const int x1[5] = {3, 1, 4, 1, 5};

int snippet(int x0);
int snippet(int x0) {
  int x2 = 5;
  int * x3 = (int *)malloc(sizeof(int) * x2);
  int x4 = 5;
  memcpy(x3, x1, sizeof(int) * x4);
  int x6 = x3[x0];
  return x6;
}

