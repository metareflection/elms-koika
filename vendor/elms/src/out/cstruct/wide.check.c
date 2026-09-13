#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Wide {
  int a;
  int b;
  int c;
  int d;
  int e;
  const char * f;
};

int snippet(struct Wide * x0);
int snippet(struct Wide * x0) {
  int x1 = x0->c;
  return x1;
}

