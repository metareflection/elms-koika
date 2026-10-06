#include <stdbool.h>

int snippet(char x0);
int snippet(char x0) {
  char x1 = '0';
  bool x2 = (unsigned char)x1 <= (unsigned char)x0;
  bool x5 = x2;
  if (x5) {
    char x3 = '9';
    bool x4 = (unsigned char)x0 <= (unsigned char)x3;
    x5 = x4;
  }
  int x8;
  if (x5) {
    int x6 = 1;
    x8 = x6;
  } else {
    int x7 = 0;
    x8 = x7;
  }
  return x8;
}

