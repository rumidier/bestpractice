#include <stdio.h>

char *
equal_compare (char *st1,
               char *st2)
{
  int i;
  int str1_num;
  int str2_num;

  str1_num = 0;
  str2_num = 0;

  i = 0;
  while (*(st1 + i)!= '\0')
    {
      str1_num++;
      i++;
    }

  i = 0;
  while (*(st2 + i) != '\0')
    {
      str2_num++;
      i++;
    }

  if (str1_num == str2_num)
      return NULL;
  else if (str1_num > str2_num)
      return st1;
  else
      return st2;
/**
  while (1)
    {
      if (*(str1 + i) == '\0' && *(str2 + i) == '\0')
        return NULL;
      else if (*(str1 + i) == '\0')
        return str2;
      else if (*(str2 + i) == '\0')
        return str1;

      i++;
    }
*/
//기본 적인 소스
}

int
main (int   argc,
      char *argv[])
{
  char *equal_num;
  char str1[] = "C Programming";
  char str2[] = "Java Program";

  equal_num = equal_compare (str1, str2);

  if (equal_num == NULL)
    printf ("두 문자열의 길이가 동일 합니다. \n");
  else
    printf ("긴 문자열 : %s\n", equal_num);

  return 0;
}
