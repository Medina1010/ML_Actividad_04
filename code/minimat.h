#ifndef MINIMAT_H
#define MINIMAT_H

#include <complex.h>
#include <math.h>

typedef int i32;
typedef float f32;
typedef float complex z32;

void ft(const z32 *x, z32 *fx, i32 N);
void ift(const z32 *fx, z32 *x, i32 N);
void haar_step(const z32 *x, z32 *A, z32 *D, i32 N, i32 N2);
f32 z_dot(z32* x, z32* y, i32 N);

#ifdef MINIMAT_H_IMPLEMENTATION

void ft(const z32 *x, z32 *fx, i32 N) {
  for (i32 k = 0; k < N; k++) {
    fx[k] = (z32){0, 0};
    for (i32 n = 0; n < N; n++) {
      fx[k] += x[n] * cexp(-2 * M_PI * I * k * n / N);
    }
  }
}
void ift(const z32 *fx, z32 *x, i32 N) {
  for (i32 k = 0; k < N; k++) {
    fx[k] = (z32){0, 0};
    for (i32 n = 0; n < N; n++) {
      x[k] += fx[n] * cexp(2 * M_PI * I * k * n / N);
    }
  }
}

void haar_step(const z32 *x, z32 *A, z32 *D, i32 N, i32 N2) {
  for (i32 i = 0; i < N2 / 2; i++) {
    A[i] = (x[(2 * i) % N] + x[(2 * i + 1) % N]) * sqrt(2.0) * 0.5;
    D[i] = (x[(2 * i) % N] - x[(2 * i + 1) % N]) * sqrt(2.0) * 0.5;
  }
}

void ihaar_step(const z32 *A, const z32 *D, z32 *x, i32 N, i32 N2) {
  for (i32 i = 0; i < N2 / 2; i++) {
    x[(2 * i) % N] = (A[i] + D[i]) * sqrt(2.0) * 0.5;
    x[(2 * i + 1) % N] = (A[i] - D[i]) * sqrt(2.0) * 0.5;
  }
}

f32 z_dot(z32* x, z32* y, i32 N) {
  f32 result = 0;
  for (i32 i = 0; i < N; i++)
    result += x[i] * y[i];
  return result;
}

#endif // MINIMAT_H_IMPLEMENTATION

#endif // MINIMAT_H
