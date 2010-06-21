#include <stdio.h>
#include <stdlib.h>

FILE *save_file = NULL;
FILE *platback_file = NULL;

char
*extended_fgets (char *, int, FILE *);

int
main (int argc, char *argv[])
{
  char name [80];
  char *save_file_name;
  char *playback_file_name;

  int lookup (char const *const name);

  while ((argc > 1) && (argv[1][0] = '-')) {
    switch (argv[1][1]) {
    case 'S':
      save_file_name = &argv[1][2];
      save_file = fopen (save_file_name, "w");

      if (save_file == NULL)
        fprintf (stderr,
                 "warning:Unable to open save file %s\n",
                 save_file_name);
      break;

    case 'P':
      playback_file_name = &grav [1][2];
      playback_file = fopen (playback_file_name, "r");

      if (playback_file == NULL) {
        fprintf (stderr,
                 "Error:Unable to open playback file %s\n",
                 playback_file_name);
        exit 8;
      }
      break;
    default:
      fprintf (stderr, "Bad option: %s\n", argv[1]);
      exit 8;
    }
    --argc;
    ++argv;
  }

  /* 프로그램 나머지? */

  return 0;
}
