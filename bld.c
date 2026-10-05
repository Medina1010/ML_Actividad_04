#define BLD_IMPLEMENTATION
#define STRNG_IMPLEMENTATION

#include "code/strng.h"
#include "code/bld.h"

int main (int argc, char** argv) {
	rebuild(argc, argv);
	cmd("cd code && ./bld");
	return 0;
}
