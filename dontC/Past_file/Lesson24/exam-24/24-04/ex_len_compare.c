#include <stdio.h>

char *retlongstr (char *st1, char *st2);

int
main (int   argc,
      char *argv[])
{
  char str1[] = "C Programming";
  char str2[] = "Java Program";
  char *longstr;

  longstr = retlongstr (str1, str2);

  if (longstr == NULL)
    printf ("두 문자열의 길이가 동일 합니다.\n");
  else
    printf ("긴 문자열 : %s \n", longstr);

  return 0;
}

char *
retlongstr (char *st1,
           char *st2)
{
  int i = 0;

  while (1)
    {
      if (*(st1 + i) == '\0' && *(st2 + i) == '\0')
        return NULL;
      else if (*(st1 + i) == '\0')
        return st2;
      else if (*(st2 + i) == '\0')
        return st1;
      else
        i++;
    }
}
