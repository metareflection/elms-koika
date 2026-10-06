//@ requires x0 > 0;
//@ ensures \result > 0;
int snippet(int x0);
int snippet(int x0) {
  int x1 = 1;
  int x2 = x0 + x1;
  return x2;
}

