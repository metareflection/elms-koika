#include <stdlib.h>
#include <string.h>

struct Point {
  int x;
  int y;
};

int snippet(int x0);
int snippet(int x0) {
  int x1 = 2;
  struct Point * * x2 = (struct Point * *)malloc(sizeof(struct Point *) * x1);
  int x3 = 2;
  struct Point * * x4 = (struct Point * *)malloc(sizeof(struct Point *) * x3);
  int x5 = 2;
  memcpy(x4, x2, sizeof(struct Point *) * x5);
  return x0;
}

