#include <stdio.h>
#include <string.h>

char
wordcopy (char    src[],
          char    dest[]);

int
main (int   argc,
      char *argv[])
{
  char word1[20] = "Orange";
  char word2[20] = "Programming";
  char buf1[20];
  char buf2[20];

  wordcopy (word1, buf1);
  wordcopy (word2, buf2);

  printf ("복사본 1 : %s \n", buf1);
  printf ("복사본 2 : %s \n", buf2);

  return 0;
}

char
wordcopy (char   src[],
          char   dest[])
{
  int temp;
  int count, i;
  count = strlen (src);

  for (i = 0; i < count + 1; i++)
    {
      temp = src[i];
      dest[i] = temp;
    }

  return *dest;
}
