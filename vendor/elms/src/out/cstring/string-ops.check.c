#include <stdbool.h>
#include <string.h>
#include "elms_lib.h"

int snippet(const char * x0);
int snippet(const char * x0) {
  int x1 = 0;
  char x2 = x0[x1];
  const char * x3 = "he";
  bool x4 = elms_str_startswith(x0, x3);
  int x15;
  if (x4) {
    int x5 = 1;
    x15 = x5;
  } else {
    const char * x6 = "lo";
    bool x7 = elms_str_endswith(x0, x6);
    int x14;
    if (x7) {
      int x8 = 2;
      x14 = x8;
    } else {
      char x9 = 'x';
      bool x10 = x2 == x9;
      int x13;
      if (x10) {
        int x11 = 3;
        x13 = x11;
      } else {
        int x12 = 0;
        x13 = x12;
      }
      x14 = x13;
    }
    x15 = x14;
  }
  int x16 = (int)strlen(x0);
  int x17 = 2;
  const char * x18 = elms_str_drop(x0, x17);
  int x19 = (int)strlen(x18);
  int x20 = x16 + x19;
  int x21 = 3;
  const char * x22 = elms_str_take(x0, x21);
  int x23 = (int)strlen(x22);
  int x24 = x20 + x23;
  int x25 = 1;
  int x26 = 4;
  const char * x27 = elms_str_substring(x0, x25, x26);
  int x28 = (int)strlen(x27);
  int x29 = x24 + x28;
  int x30 = x29 + x15;
  return x30;
}

