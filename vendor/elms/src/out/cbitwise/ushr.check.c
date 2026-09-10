#include <stdbool.h>
#include <stdlib.h>

int snippet(int x0);
int snippet(int x0) {
  int x1 = 4;
  int x2 = (int)((unsigned int)x0 >> x1);
  return x2;
}

