#include <stdio.h>

int
main (int argc, char *argv[])
{
  FILE *fp;
  unsigned char buf[16];
  unsigned int addr = 0;
  int readnum, i;

  if (argc <= 1) {
    printf ("usage: dump filename\n");
    return 1;
  }
  if (!(fp = fopen (argv[1], "rb"))) {
    printf ("파일을 열지 못했습니다.\n");
    return 1;
  }

  while (1) {
    printf ("%08X ", addr);
    readnum = fread (buf, 1, 16, fp);
    for (i = 0; i < readnum; i++) {
      if (i == 8)
        printf (" ");
      printf ("%02X ", buf[i]);
    }
    for (i = readnum; i < 16; i++) {
      if (i == 8)
        printf (" ");
      printf ("   ");
    }
    printf (" ");

    for (i = 0; i < readnum; i++)
      printf ("%c", (32 <= buf[i] && buf[i] <= 126) ? buf[i] : '.');
    printf ("\n");
    addr += 16;
    if (feof (fp))
      break;
  }
  fclose (fp);

  return 0;
}
