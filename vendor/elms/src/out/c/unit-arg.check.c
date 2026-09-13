#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int snippet(int x0);
int x1(void);
int snippet(int x0) {
  ;
  int x5 = x1();
  int x6 = x5 + x0;
  return x6;
}

int x1(void) {
  int x3 = 7;
  return x3;
}

