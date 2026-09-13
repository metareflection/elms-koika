#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Foo {
  int x;
  const char * y;
};

void snippet(struct Foo * x0);
void snippet(struct Foo * x0) {
  x0->x = 6;
  /* unit */;
}

