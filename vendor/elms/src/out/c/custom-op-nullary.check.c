#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int now(void);

int snippet(int x0);
int snippet(int x0) {
  int x1 = now();
  int x2 = x1 + x0;
  return x2;
}

