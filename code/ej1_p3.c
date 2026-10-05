#define MINIMAT_H_IMPLEMENTATION
#include "minimat.h"

int main (void) {
  z32 fx[N] = {1,2-I,3+I,4,5};
  z32 x[];
  i32 N = sizeof(fx)/sizeof(*fx);
  ift(fx, x, N);
  return 0;
}
