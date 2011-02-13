#include <stdio.h>
#include <string.h>

int
wordlen (char str[]);

int
main (int   argc,
      char *argv[])
{
  char wordbuf[100];
  printf ("Word Input : ");
  scanf ("%s", wordbuf);
  printf ("Word length : %d \n", wordlen (wordbuf));

  return 0;
}

int
wordlen (char str[])
{
  int str_len;

  str_len = strlen(str);

  return str_len;
}
