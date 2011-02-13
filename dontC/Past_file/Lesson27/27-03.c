#include <stdio.h>

void addproc (void);
void minusproc (void);
void callfunc (void (*fctptr) (void));

int
main (int   argc,
      char *argv[])
{
  callfunc (addproc);
  callfunc (minusproc);

  return 0;
}

void
callfunc (void (*fctptr) (void))
{
  fctptr ();
}

void
addproc (void)
{
  int n1, n2;
  printf ("덧셈 위한 두 개의 정수 입력 : ");
  scanf ("%d %d", &n1, &n2);
  printf ("덧셈 결과 : %d \n\n", n1 + n2);
}

void
minusproc (void)
{
  int n1, n2;
  printf ("뺄셈 위한 두 개의 정수 입력 : ");
  scanf ("%d %d", &n1, &n2);
  printf ("뺄셈 결과 : %d \n\n", n1 - n2);
}
