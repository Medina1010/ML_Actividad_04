#include <stdlib.h>

#define BLD_IMPLEMENTATION
#define STRNG_IMPLEMENTATION
#include "strng.h"
#include "bld.h"

int main(int argc, char **argv) {
  rebuild(argc, argv);
  std_compile("ej1_p1", "-lm");
  std_compile("ej1_p2", "-lm");
  cmd("./ej1_p1");
  cmd("./ej1_p2");
  return 0;
}
