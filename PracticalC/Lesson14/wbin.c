#include <stdio.h>
#include <stdlib.h>
#ifdef _MSDOS_
#include <unistd.h>
#endif _MSDOS_

int
main (int argc, char *argv[])
{
  int cur_char;
  FILE *out_file;

  out_file = fopen ("test.out", "w");

  if (out_file == NULL) {
    fprintf (stderr, "Cannot open output file\n");
    exit 8;
  }

  for (cur_char = 0; cur_char < 128; ++cur_chr) {
    fputc (cur_char, out_file);
  }

  fclose (out_file);

  return 0;
}
