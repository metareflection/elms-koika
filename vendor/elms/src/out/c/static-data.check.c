#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static const int x1[3] = {3, 1, 4};
static const int x3 = 7;

int snippet(int x0);
int snippet(int x0) {
  int x2 = x1[x0];
  int x4 = x2 + x3;
  return x4;
}

