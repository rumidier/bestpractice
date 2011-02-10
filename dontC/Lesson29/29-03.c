#include <stdio.h>

void clear_read_buffer (void);

int
main (int   argc,
      char *argv[])
{
  int ch;
  char str[20];

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
      putchar ('\n');
    }

  /* fflush (stdin) 대행 */
  clear_read_buffer ();

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

void
clear_read_buffer (void)
{
  while (getchar () != '\n');
}
