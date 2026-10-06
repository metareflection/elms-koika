struct Buffer {
  int xs[16];
  int n;
};

void snippet(struct Buffer * x0);
void snippet(struct Buffer * x0) {
  int * x1 = x0->xs;
  /* ERROR: cannot assign to the fixed-length member `xs` as a whole: C has no assignment operator for an array; write through it with `.set(i, x)` */;
  /* unit */;
}

