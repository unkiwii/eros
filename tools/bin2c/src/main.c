#include <stdio.h>
#include <stdlib.h>

void usage(char* program)
{
  printf("Usage: %s name\n", program);
  exit(-1);
}

int main(int argc, char** argv)
{
  if (argc != 2) {
    usage(argv[0]);
  }

  int c;
  printf("unsigned char %s[] = {\n  ", argv[1]);
  while ((c = fgetc(stdin)) != EOF) {
    printf("'\\x%X',", (unsigned)c);
  }
  printf("'\\0'");

  return 0;
}
