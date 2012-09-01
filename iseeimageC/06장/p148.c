#include <stdio.h>
#include <string.h>

int
main (int argc, char *argv[])
{
  FILE *fpr, *fpw;
  char bufr[256], bufw[256];
  char str1 [] = "dog";
  char str2 [] = "rabbit";
  char *p, *q;

  if (!(fpr = fopen ("dog.txt", "r"))) {
    printf ("파일을 읽어 오지 못했습니다.");
    return 1;
  }
  if (!(fpw = fopen ("rabbit.txt", "w"))) {
    printf ("작성할 파일을 열지 못했습니다.");
    return 2;
  }

  while (1) {
    fgets (bufr, 256, fpr);
    if (feof(fpr))
      break;
    strcpy (bufw, bufr);
    p = strstr (bufr, str1);

    if (p) {
      q = bufw + (p - bufr);
      strcpy (q, str2);
      strcpy (q + strlen (str2), p + strlen (str1));
    }
    fprintf (fpw, "%s", bufw);
  }
  fclose (fpr);
  fclose (fpw);

  return 0;
}
