/**
 * 주민등록번호 확인 프로그램
 *
 *   난 정말 C Programming을 공부한 적이 없다구요!
 *   p.503, 문제 6
 */

#include <stdio.h>

#define BUF_LEN   256

int
main (int   argc,
      char *argv[])
{
  while (1)
    {
      int year;
      int month;
      int day;
      int gender;
      int remain;

      printf ("주민등록 번호('-' 기호 포함)를 입력하세요: ");
      scanf ("%02d%02d%02d-%1d%06d", &year, &month, &day, &gender, &remain);

      printf ("year:   [%d]\n", year);
      printf ("month:  [%d]\n", month);
      printf ("day:    [%d]\n", day);
      printf ("gender: [%d]\n", gender);
      printf ("remain: [%d]\n", remain);
    }

  return 0;
}
