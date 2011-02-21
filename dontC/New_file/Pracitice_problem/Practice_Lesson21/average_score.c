#include <stdio.h>
#include <malloc.h>

int
main (int   argc,
      char *argv[])
{
  int **score = NULL;
  double mid_score;
  double last_score;
  int count;
  int i;

  count = 0;
  mid_score = 0;
  last_score = 0;

  score = (int **) realloc (score, 2 * sizeof (int *));
  score[0] = (int *) realloc (NULL, 7 * sizeof (int));
  score[1] = (int *) realloc (NULL, 7 * sizeof (int));
  score[2] = NULL;

  while (1)
    {
      printf ("학생 %d의 중간 기말 점수 입력 : ", count + 1);
      scanf ("%d %d", &score[0][count], &score[1][count]);
      count++;

      if (count >= 7)
        break;
    }

  for (i = 0; i < 7; i++)
    {
      mid_score += score[0][i];
    }
  for (i = 0; i < 7; i++)
    {
      last_score += score[1][i];
    }

  printf ("중간 고사 평균 : %g\n기말 고사 평균 : %g\n", mid_score / 7, last_score / 7);


  return 0;
}
