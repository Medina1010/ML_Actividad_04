#ifndef BLD_H
#define BLD_H

int cmd(char *prompt);
int rebuild(int argc, char **argv);
int std_compile(char *name, char *extra);

#ifdef BLD_IMPLEMENTATION

int cmd(char *prompt) {
  printf("[BLD]: %s\n", prompt);
  return system(prompt);
}

int rebuild(int argc, char **argv) {
  if (argc == 1) {
    std_compile("bld", "");
    cmd("./bld RBD");
    exit(0);
  }
  return 0;
}

int std_compile(char *name, char *extra) {
  strng command = {0};
  strng_append_cstr(&command, "gcc -o ");
  strng_append_cstr(&command, name);
  strng_append_cstr(&command, " ");
  strng_append_cstr(&command, name);
  strng_append_cstr(&command, ".c");
  strng_append_cstr(&command, " ");
  strng_append_cstr(&command, extra);
  int result = cmd(strng_cstr(&command));
  free(command.data);
  return result;
}

#endif // BLD_IMPLEMENTATION

#endif // BLD_H
