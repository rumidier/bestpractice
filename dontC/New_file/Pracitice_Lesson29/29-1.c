#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int ch;
  char str[20];

  /* 문자열의 입력과 출력 */
  if (gets (str) == NULL)
    {
      printf ("문자열 READ 실패 \n");
      return -1; // 오류 발생으로 인한 프로그램 종료
    }
  else
    {
      if (puts (str) == EOF)
        printf ("문자열 WRITE 실패 \n");
    }
  /* 문자의 입력과 출력 */
  if ((ch = getchar ()) == EOF)
    {
      printf ("문자 READ 실패 \n");
      return -1;
    }
  else
    {
      if (putchar (ch) == EOF)
        printf ("문자 WRITE 실패 \n");
      putchar ('\n'); //한 줄 건너뛰기 위해!
    }

  return 0;
}
