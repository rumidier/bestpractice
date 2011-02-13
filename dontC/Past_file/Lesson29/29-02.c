#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int ch;
  char str[20];

  if ((ch = getchar()) == EOF)
    {
      printf ("문자 READ 실패 \n");
      return -1;
    }
  else
    {
      if (putchar (ch) == EOF)
        printf ("문자 WRITE 실패 \n");
      putchar ('\n');
    }

  /* 문자열의 입력과 출력 */
  if (gets (str) == NULL)
    {
      printf ("문자열 READ 실패 \n");
      return -1;
    }
  else
    {
      if (puts (str) == EOF)
        printf ("문자열 WRITE 실패 \n");
    }

  return 0;
}
