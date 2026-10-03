#ifndef MINIMAT_H
#define MINIMAT_H
#include <math.h>

typedef int i32;
typedef float f32;
typedef struct {
  f32 a, b;
} z32;

z32 z_sum(z32 z1, z32 z2);
z32 z_times(z32 z1, z32 z2);
z32 z_exp(z32 z);
void ft(const z32* x, z32* fx, i32 N);

#ifdef MINIMAT_H_IMPLEMENTATION

z32 z_sum(z32 z1, z32 z2) {
  return (z32){.a = z1.a + z2.a, .b = z1.b + z2.b};
}

z32 z_times(z32 z1, z32 z2) {
  return (z32){.a = z1.a * z2.a - z1.b * z2.b, .b = z1.a * z2.b + z1.b * z2.a};
}

z32 z_exp(z32 z) {
  return (z32){.a = exp(z.a) * cos(z.b), .b = exp(z.a) * sin(z.b)};
}

void ft(const z32* x, z32* fx, i32 N) {
  for (i32 k = 0; k < N; k++) {
    fx[k] = (z32){0,0};
    for (i32 n = 0; n < N; n++) {
      fx[k] = z_sum(
          fx[k], z_times(x[n], z_exp((z32){.a = 0, .b = -2 * M_PI * k * n / N})));
    }
  }
}

#endif // MINIMAT_H_IMPLEMENTATION

#endif // MINIMAT_H
