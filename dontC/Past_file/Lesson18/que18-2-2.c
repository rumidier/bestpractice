#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char str[100];
  int diff = 'A' - 'a';
  int i = 0;

  printf ("문자열 입력 : ");
  scanf ("%s", str);

  while (str[i] != '\0')
         {
           if ('a' <= str[i] && str[i] <= 'z')
             str[i] += diff;
           i++;
         }

  printf ("변경된 문자열 : %s \n", str);

  return 0;
}
