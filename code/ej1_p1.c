#include <stdio.h>

#define MINIMAT_H_IMPLEMENTATION
#include "minimat.h"

#define CMPLX_FMT "%f%c%fi"
#define CMPLX_ARGS(z) creal(z), cimag(z) < 0 ? '-' : '+', fabs(cimag(z))

i32 main(void) {
  z32 x[] = {1,2-I,3+I,4,5};
  i32 N = sizeof(x)/sizeof(*x);
  z32 fx[N];
  ft(x, fx, N);
  f32 important_energy = sqrt(z_dot(fx,fx,N)) * 0.95;
  f32 acumulate = 0;
  i32 i = 0;
  while (sqrt(acumulate) < important_energy){
    acumulate += fx[i] * fx[i]; i++;
  }
  for (int j = i; j < N; j++)
    fx[j] = 0;
  return 0;
}
