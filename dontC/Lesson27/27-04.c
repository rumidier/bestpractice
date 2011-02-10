#include <stdio.h>

void addproc (void);
void minusproc (void);
void (*retfuncptr (int sel)) (void); //retfuncptr 함수의 선언

int
main (int   argc,
      char *argv[])
{
  void (*fctptr) (void);

  fctptr = retfuncptr (1);
  fctptr ();

  fctptr = retfuncptr (2);
  fctptr ();

  return 0;
}

void 
(*retfuncptr (int sel)) (void)
{
  if (sel == 1)
    return addproc;
  else
    return minusproc;
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
