#include <stdlib.h>

#define BLD_IMPLEMENTATION
#define STRNG_IMPLEMENTATION
#include "bld.h"

int main(int argc, char **argv) {
  rebuild(argc, argv);
  std_compile("punto_1", "-lm");
  cmd("time ./punto_1");
  return 0;
}
