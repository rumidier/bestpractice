/**
 * 주민등록번호 확인 프로그램
 *
 *   난 정말 C Programming을 공부한 적이 없다구요!
 *   p.503, 문제 6
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
at_num (char str[])
{
  int num;

  num = atoi (str);

  return num;
}

int
main (int   argc,
      char *argv[])
{
  char buf[256];
  char num[256];
  int count, i, mm, dd, s;

  while (1)
    {
      printf ("바(-)를 포함한 주민등록번호 입력 : ");
      scanf ("%s", buf);
      count = strlen (buf);

      if (count != 14)
        break;

      for (i = 0; i < 2; i++)
        {
          num[i] = buf[2 + i];
        }
      mm = at_num (num);

      if (1 <= mm && mm <= 12)
        {
          for (i = 0; i <2; i++)
            {
              num[i] = buf[4 + i];
            }
          dd = at_num (num);

          if (mm == 2)
            {
              if (1 <= dd && dd <= 29)
                {
                  s = buf[7];
                  printf ("%d\n", s);

                  if ( s == 1 || s == 2)
                    {
                      printf ("정상적인 주민번호 입력에 감사드립니다.\n");
                      break;
                    }
                  else
                    {
                      printf ("성별 정보가 잘못되었습니다\n");
                    }
                }
              else
                {
                  printf ("일 정보가 잘못되었습니다.\n");
                  continue;
                }
            }
          else
            {
              if (1 <= dd && dd <= 31)
                {
                  s = buf[7];
                  printf ("%d\n", s);

                  if (s == 1 || s == 2)
                    {
                      printf ("정상적인 주민번호 입력에 감사드립니다.\n");
                      break;
                    }
                  else
                    {
                      printf ("성별 정보가 잘못되었습니다\n");
                      break;
                    }
                }
              else
                {
                  printf ("일 정보가 잘못되었습니다.\n");
                  continue;
                }
            }
        }
      else
        {
              printf ("월 정보가 잘못되었습니다.\n");
              continue;
        }
    }

  return 0;
}
