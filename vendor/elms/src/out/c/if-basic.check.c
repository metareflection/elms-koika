#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int snippet(bool x0);
int snippet(bool x0) {
  int x3;
  if (x0) {
    int x1 = 1;
    x3 = x1;
  } else {
    int x2 = 0;
    x3 = x2;
  }
  return x3;
}

