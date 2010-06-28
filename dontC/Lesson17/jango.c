#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  double accarr[5];
  double rate;
  int i;

  for (i = 0; i < 5; i++)
    {
      printf ("잔고 입력 : ");
      scanf ("%1f", &rat
             );

      for (i = 0; i < 5; i++)
        accarr[i] *= (1 + rate / 100.0);

      printf ("이자가 반영된 잔고 조회 \n");
      for (i = 0; i < 5; i++)
        printf ("계좌 %d : %g \n", i + 1, accarr[i]);
    }

  return 0;
}
