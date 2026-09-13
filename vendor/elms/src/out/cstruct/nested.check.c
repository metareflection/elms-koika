#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Nested {
  struct Bar * b;
  int n;
};

struct Bar {
  int z;
};

int snippet(struct Nested * x0);
int snippet(struct Nested * x0) {
  int x1 = x0->n;
  return x1;
}

