#include <stdio.h>

//#define     STR(A)                  #A
#define     STRING_JOB(A, B)       #A "의 직업은" #B "입니다."
#define     PRINT_STR(STR)        puts (STR);

int
main (int   argc,
      char *argv[])
{
#if 0
  printf (STR (%s의 직업은 %s입니다.\n), STR (이동춘), STR (나무꾼));
  printf (STR (%s의 직업은 %s입니다.\n), STR (한상순), STR (사냥꾼));
#endif

  PRINT_STR (STRING_JOB (이동춘, 나무꾼));
  PRINT_STR (STRING_JOB (한상순, 사냥꾼));

  return 0;
}
