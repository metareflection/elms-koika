#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool snippet(int x0);
bool snippet(int x0) {
  int x1 = 0;
  bool x2 = x0 > x1;
  bool x12 = x2;
  if (x12) {
    const char * x3 = "checking";
    printf("%s\n", x3);
    int x5 = 5;
    bool x6 = x0 > x5;
    bool x11;
    if (x6) {
      int x7 = 100;
      bool x8 = x0 < x7;
      x11 = x8;
    } else {
      int x9 = 3;
      bool x10 = x0 == x9;
      x11 = x10;
    }
    x12 = x11;
  }
  return x12;
}

