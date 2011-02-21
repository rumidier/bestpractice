#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char jumin_str[14];
  int m_num;
  int d_num;
  int s_num;

  m_num = 0;
  d_num = 0;
  s_num = 0;


  while (1)
    {
      printf ("바(-)를 포함한 주민등록번호 입력 : ");
      scanf ("%s", jumin_str);

      if (strlen (jumin_str) != 14)
        {
          printf ("잘못된 주민등록 정보 입니다 다시 입력해 주세요\n");
          continue;
        }

      m_num = jumin_str[2] - 48;
      m_num *= 10;
      m_num += jumin_str[3] - 48;

      d_num = jumin_str[4] - 48;
      d_num *= 10;
      d_num += jumin_str[5] - 48;

      s_num = jumin_str[7] - 48;

      if ( !(m_num >= 1 && m_num <= 12))
        {
          printf ("월 정보가 잘못되었습니다.\n");
          continue;
        }
      else if (m_num == 2)
        {
          if ( !(d_num >= 1 && d_num <= 29))
            {
              printf ("일 정보가 잘못되었습니다.\n");
              continue;
            }
        }
      else if ( !(d_num >= 1 && d_num <= 31))
        {
          printf ("일 정보가 잘못되었습니다.\n");
          continue;
        }
      else if (s_num != 1 &&  s_num != 2)
        {
          printf ("성별이 잘못 입력 되었습니다\n");
          continue;
        }

      printf ("정상적인 주민번호 입력에 감사 드립니다\n");
      break;
    }

  return 0;
}
