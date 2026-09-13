#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Buffer {
  int xs[16];
  int n;
};

int snippet(struct Buffer * x0);
int snippet(struct Buffer * x0) {
  int * x1 = x0->xs;
  int x3 = 16;
  return x3;
}

