#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char str[] = "AAA-BBB_CCC-DDD!EEE";
  char *tok;
  int cnt = 0;

  tok = strtok (str, "-_!");

  while (tok != NULL)
    {
      cnt++;
      printf ("토큰 %d : %s \n", cnt, tok);
      tok = strtok (NULL, "-_!");
    }

  return 0;
}
