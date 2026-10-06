#include <stdbool.h>

int snippet(char x0);
int snippet(char x0) {
  char x1 = 'a';
  bool x2 = (unsigned char)x0 >= (unsigned char)x1;
  int x5;
  if (x2) {
    int x3 = 1;
    x5 = x3;
  } else {
    int x4 = 0;
    x5 = x4;
  }
  return x5;
}

