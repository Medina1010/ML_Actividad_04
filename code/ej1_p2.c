#include <stdio.h>

#define MINIMAT_H_IMPLEMENTATION
#include "minimat.h"

i32 main(void) {
  z32 x[] = {1,2,3,4,5};
  i32 N = sizeof(x)/sizeof(*x);
  i32 N2 = pow(2, (int)(log(N) / log(2)) + 1);
  printf("%d\n", N2);
  z32 R1[N2];
  z32 R2[N2 / 2];
  haar_step(x, R1, &R1[N2 / 2], N, N2);
  haar_step(R1, R2, &R2[N2 / 4], N2 / 2, N2 / 2);
  haar_step(R2, R1, &R1[N2 / 8], N2 / 4, N2 / 4);
  haar_step(R1, R2, &R2[N2 / 16], N2 / 8, N2 / 8);
  haar_step(R2, R1, &R1[N2 / 32], N2 / 16, N2 / 16);
  return 0;
  }
