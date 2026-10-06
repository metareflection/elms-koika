#include <stdlib.h>

void snippet(int x0);
void snippet(int x0) {
  int * x1 = (int *)malloc(sizeof(int) * x0);
  int x2 = 0;
  for (int x4 = x2; x4 < x0; x4++) {
    int x7 = 2;
    int x8 = x4 * x7;
    x1[x4] = x8;
    /* unit */;
  }
  ;
  /* unit */;
}

