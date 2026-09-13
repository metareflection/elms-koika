#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int snippet(int x0);
int snippet(int x0) {
  const char * x1 = "s";
  printf("%s\n", x1);
  printf("%d\n", x0);
  int x4 = 0;
  bool x5 = x0 > x4;
  printf("%s\n", x5 ? "true" : "false");
  char x7 = 'c';
  printf("%c", x7);
  return x0;
}

