#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Buffer {
  int xs[16];
  int n;
};

void snippet(struct Buffer * x0);
void snippet(struct Buffer * x0) {
  int * x1 = x0->xs;
  /* ERROR: Cannot assign to fixed-length array member `xs` */;
  /* unit */;
}

