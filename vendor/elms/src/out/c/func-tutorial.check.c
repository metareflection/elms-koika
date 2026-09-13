#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int snippet(int x0);
int snippet(int x0) {
  int x1 = 1;
  bool x2 = x0 == x1;
  int x4;
  if (x2) {
    int x3 = 1;
    x4 = x3;
  } else {
    x4 = x0;
  }
  return x4;
}

