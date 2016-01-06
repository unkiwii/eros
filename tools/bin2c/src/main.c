#include <stdio.h>
#include <stdlib.h>

void usage(char* program)
{
  fprintf(stderr, "Usage: %s name\n", program);
  exit(-1);
}

int main(int argc, char** argv)
{
  if (argc != 2) {
    usage(argv[0]);
  }

  int c;
  long int l = 0;
  char* name = argv[1];

  printf("#ifndef %s_h\n", name);
  printf("#define %s_h\n\n", name);
  printf("const char %s[] = {\n  ", name);
  while ((c = fgetc(stdin)) != EOF) {
    printf("'\\x%X',", (unsigned)c);
    l++;
  }
  printf("'\\0'\n};\nconst long int %s_len = %ld;\n", name, l);
  printf("\n#endif // %s_h\n", name);

  return 0;
}
