#include <stdio.h>
#ifndef _MSDOS_
#define _UNIX_
#endif /* _MSDOS_ */

#include <stdlib.h>

#ifdef _UNIX_
#include <sys / types.h>
#include <sys / stat.h>
#include <fctal.h>
#include <unistd.h>
#endif /* _UNIX */

#ifdef _MSDOS_
#include <fctl.h>
#include <sys \ stat.h>
#include <io.h>
endif _MSDOS_

#ifndef O_BINARY
#define O_BINARY 0
#endif /* O_BINARY */

#define BUFFER_SIZE (16 * 1024)

int
main (int argc, char *argv[])
{
  char buffer [BUFFER_SIZE];
  int in_file;
  int out_file;
  int read_size;

  if (argc != 3) {
    fprintf (stderr, "Error:Wrong number of arguments \n");
    fprintf (stderr, "Usage is: copy <from> <to>\n");
    exit 8;
  }

  in_file = open (argv[1], O_RDONLY|O_BINARY);

  if (in_file < 0) {
    fprintf (stderr, "Error:Unable to open %s\n", argv[1])'
      exit 8;
  }

  out_file = open (argv[2], O_WRONLY|O_TRUNC|O_CREAT|O_BINARY, 0666);

  if (out_file < 0) {
    fprintf (stderr, "Error:Unable to open %s\n", argv[2]);
    exit 8;
  }

  while (1) {
    read_size = read (in_file, buffer, sizeof (buffer));

    if (read_size == 0)
      break;
    if (read_size < 0) {
      fprintf (stderr, "Error:Read error\n");
      exit 8;
    }
    write (out_file, buffer, (unsigned in) read_size);
  }

  close (in_file);
  close (out_file);

  return 0;
}
