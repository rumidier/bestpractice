#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i;
  int count;
  int fir_score = 0;
  int sd_score = 0;
  int input[10];
  count = 0;

  while (count <= 9)
    {

      printf ("수강생의 점수를 입력해 주세요: ");
      scanf ("%d", &input[count]);

      count++;
    }

  for (i = 0; i < count; i++)
    {
      if (input[i] > fir_score)
        {
          fir_score = input[i];
        }
      else if (input[i] < fir_score && input[i] > sd_score)
        {
          sd_score = input[i];
        }
      printf ("%d \n", input[i]);
    }

  printf ("A학점은 최소 %d점 이상입니다.\n", sd_score);

  return 0;
}
