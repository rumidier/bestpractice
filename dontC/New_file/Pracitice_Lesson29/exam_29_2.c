#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i;
  int num;
  int c;
  char str[20];

  for (i = 0; i < 2; i++)
    {
      if (i == 0)
        {
          printf ("문자열 입력 : ");
          gets (str);
        }
      else if (i == 1)
        {
          printf ("문자 & 정수 입력 : ");
          c = getchar ();
          scanf ("%d", &num);
        }
    }
  printf ("문자열 %s \n", str);
  printf ("문자 & 정수 : %c %d \n", c, num);
#if 0
  char str[10];
  int ch;
  int num;

  printf ("문자열 Read : ");
  gets (str);

  printf ("문자 & 숫자 Read : ");
  ch = getchar ();
  scanf ("%d", &num);

  printf ("문자열 : %s \n", str);
  printf ("문자 : %c \n", ch);
  printf ("숫자 : %d \n", num);

#endif
  return 0;
}
