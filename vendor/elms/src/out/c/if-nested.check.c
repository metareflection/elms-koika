#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int snippet(bool x0);
int snippet(bool x0) {
  int x5;
  if (x0) {
    int x3;
    if (x0) {
      int x1 = 1;
      x3 = x1;
    } else {
      int x2 = 2;
      x3 = x2;
    }
    x5 = x3;
  } else {
    int x4 = 0;
    x5 = x4;
  }
  return x5;
}

