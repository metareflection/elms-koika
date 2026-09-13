#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Foo {
  int x;
  const char * y;
};

int snippet(struct Foo * x0);
int snippet(struct Foo * x0) {
  int x1 = x0->x;
  return x1;
}

