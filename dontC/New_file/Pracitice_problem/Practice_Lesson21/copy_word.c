#include <stdio.h>
#include <string.h>

static void
word_copy (char src[], char dest[]);

int
main (int   argc,
      char *argv[])
{
  char word1[20] = "Orange";
  char word2[20] = "Programming";
  char buf1[20];
  char buf2[20];

  word_copy (word1, buf1);
  word_copy (word2, buf2);

  printf ("복사본 1 : %s \n", buf1);
  printf ("복사본 2 : %s \n", buf2);

  return 0;
}

static void
word_copy (char src[], char dest[])
{
  int i;
  int len;

  len = strlen (src);

  for (i = 0; i < len; i++)
    {
      dest[i] = src[i];
    }
  dest[i] = '\0';
}
