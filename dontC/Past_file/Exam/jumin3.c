/**
 * 주민등록번호 확인 프로그램
 *
 *   난 정말 C Programming을 공부한 적이 없다구요!
 *   p.503, 문제 6
 */

#include <stdio.h>
#include <string.h>

#define BUF_LEN   256

int
main (int   argc,
      char *argv[])
{
  while (1)
    {
      char buf[BUF_LEN];
      int len;

      printf ("주민등록 번호('-' 기호 포함)를 입력하세요: ");
      scanf ("%s", buf);

      /**
       * 14자인지 검사합니다.
       */
      len = strlen (buf);
      if (len != 14)
        {
          printf ("주민 번호는 14자여야합니다.\n");
          continue;
        }

      /**
       * - 기호가 있는지 검사합니다
       */
      if (buf[6] != '-')
        {
          printf ("7번째 문자는 - 기호여야합니다.\n");
          continue;
        }

      /**
       * MM(월)은 01 이상 12 이하여야 합니다.
       */
      if (
        (buf[2] != '0' && buf[2] != '1')
        || (buf[2] == '0' && !('1' <= buf[3] && buf[3] <= '9'))
        || (buf[2] == '1' && !('0' <= buf[3] && buf[3] <= '2'))
      )
        {
          printf ("월은 01 이상 12 이하여야 합니다.\n");
          continue;
        }

      /**
       * DD(일)는 01 이상 31 이하여야 합니다.
       */
      if (
        (buf[4] != '0' && buf[4] != '1' && buf[4] != '2' && buf[4] != '3')
        || (buf[4] == '0' && !('1' <= buf[5] && buf[5] <= '9'))
        || (buf[4] == '1' && !('0' <= buf[5] && buf[5] <= '9'))
        || (buf[4] == '2' && !('0' <= buf[5] && buf[5] <= '9'))
        || (buf[4] == '3' && !('0' <= buf[5] && buf[5] <= '1'))
      )
        {
          printf ("일은 01 이상 31 이하여야 합니다.\n");
          continue;
        }

      /**
       * MM이 02이면 DD는 01 이상 29 이하여야 합니다.
       */
      if (
        (buf[2] == '0' && buf[3] == '2')
        && (
          (buf[4] != '0' && buf[4] != '1' && buf[4] != '2')
          || (buf[4] == '0' && !('1' <= buf[5] && buf[5] <= '9'))
          || (buf[4] == '1' && !('0' <= buf[5] && buf[5] <= '9'))
          || (buf[4] == '2' && !('0' <= buf[5] && buf[5] <= '9'))
        )
      )
        {
          printf ("2월일 경우 일은 01 이상 29 이하여야 합니다.\n");
          continue;
        }

      /**
       * S(성별)은 1 아니면 2 입니다.
       */
      if (buf[7] != '1' && buf[7] != '2')
        {
          printf ("성별은 1 아니면 2 입니다.\n");
          continue;
        }

      break;
    }

  return 0;
}
