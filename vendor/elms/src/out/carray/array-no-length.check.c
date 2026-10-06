#include <stdlib.h>

int snippet(int x0);
int snippet(int x0) {
  int * x1 = (int *)malloc(sizeof(int) * x0);
  int x2 = 0;
  x1[x2] = x0;
  int x4 = 0;
  int x5 = x1[x4];
  return x5;
}

