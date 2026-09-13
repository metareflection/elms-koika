#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Buffer {
  int xs[16];
  int n;
};

int snippet(struct Buffer * x0);
int snippet(struct Buffer * x0) {
  int x1 = x0->n;
  return x1;
}

