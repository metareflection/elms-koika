int snippet(int x0);
int weigh(int x1, int x2, int x3);
int snippet(int x0) {
  int x10 = 7;
  int x11 = 2;
  int x12 = weigh(x0, x10, x11);
  return x12;
}

int weigh(int x1, int x2, int x3) {
  int x4 = 10;
  int x5 = x2 * x4;
  int x6 = x1 + x5;
  int x7 = 100;
  int x8 = x3 * x7;
  int x9 = x6 + x8;
  return x9;
}

