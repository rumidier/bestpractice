#include <stdio.h>
#include <stdlib.h>

void firstfunc (void);
void secondfunc (void);
void thirdfunc (void);

int
main (int   argc,
      char *argv[])
{
  if (!atexit (firstfunc))
    printf ("첫 번째 함수 정상적 등록 \n");
  if (!atexit (secondfunc))
    printf ("두 번째 함수 정상적 등록 \n");
  if (!atexit (thirdfunc))
    printf ("세 번째 함수 정상적 등록 \n\n");

  return 0;
}

void firstfunc (void)
{
  printf ("첫 번째 등록 함수. \n");
}

void secondfunc (void)
{
  printf ("두 번째 등록 함수. \n");
}

void thirdfunc (void)
{
  printf ("세 번재 등록 함수. \n");
}

