#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  printf ("현재 행 : %d \n", __LINE__);
  printf ("파일 명 : %s \n", __FILE__);
  printf ("전처리 시간 : %s \n", __TIME__);
  printf ("전처리 날짜 : %s \n", __DATE__);

  return 0;
}
