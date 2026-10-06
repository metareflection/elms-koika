#include <stdlib.h>
#include <string.h>

int snippet(int x0);
int snippet(int x0) {
  int x1 = 4;
  int * x2 = (int *)malloc(sizeof(int) * x1);
  int x3 = 0;
  x2[x3] = x0;
  int x5 = 4;
  int * x6 = (int *)malloc(sizeof(int) * x5);
  int x7 = 4;
  memcpy(x6, x2, sizeof(int) * x7);
  int x9 = 0;
  int x10 = x6[x9];
  return x10;
}

