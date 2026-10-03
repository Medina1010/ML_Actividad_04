#include <stdio.h>

#define MINIMAT_H_IMPLEMENTATION
#include "minimat.h"

void haar_step(const z32* x, z32* A, z32* D, i32 N, i32 N2) {
  for (i32 i = 0; i < N2 / 2; i++) {
    A[i] = z_times(z_sum(x[(2 * i) % N], x[(2 * i + 1) % N]),
                   (z32){sqrt(2.0f) * 0.5f, 0});
    D[i] = z_times(z_sum(x[(2 * i) % N], z_times((z32){-1, 0}, x[(2*i + 1) % N])),
                   (z32){sqrt(2.0f) * 0.5f, 0});
  }
}

i32 main(void) {
  i32 N = 47;
  z32 x[N];
  z32 fx[N];
  ft(x, fx, N);

  i32 N2 = pow(2, (int)(log(N) / log(2)) + 1);
  printf("%d\n", N2);
  z32 R1[N2];
  z32 R2[N2/2]; 
  haar_step(x, R1, &R1[N2/2], N, N2);
  haar_step(R1, R2, &R2[N2/4], N2/2, N2/2);
  haar_step(R2, R1, &R1[N2/8], N2/4, N2/4);
  haar_step(R1, R2, &R2[N2/16], N2/8, N2/8);
  haar_step(R2, R1, &R1[N2/32], N2/16, N2/16);
  return 0;
}
