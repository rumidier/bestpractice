#include <stdio.h>
#include <stdlib.h>

void funcregist (void);

int
main (int   argc,
      char *argv[])
{
  int sel;

  if (!atexit (funcregist))
    printf ("함수 정상적 등록\n");

  printf ("정상 종료 1, 비정상 종료 2 : ");
  scanf ("%d", &sel);

  if (sel == 1)
    exit (EXIT_SUCCESS);
  else
    abort ();

  return 0;
}

void funcregist (void)
{
  printf ("프로그램이 정상적으로 종료 되었습니다.\n");
}
