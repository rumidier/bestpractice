#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i;
  int mid_input, last_input;
  int mid_score[2][7];
  float mid_num, last_num;

  for (i = 0; i < 7; i++)
    {
      printf ("학생%d 의 중간 기말 점수 입력 : ", (i + 1));

      scanf ("%d %d", &mid_input, &last_input);
      mid_score[0][i] = mid_input;
      mid_score[1][i] = last_input;
    }

    mid_num = mid_score[0][0] + mid_score[0][1] + mid_score[0][2] +
              mid_score[0][3] + mid_score[0][4] + mid_score[0][5] +
              mid_score[0][6];

    last_num = mid_score[1][0] + mid_score[1][1] + mid_score[1][2] +
              mid_score[1][3] + mid_score[1][4] + mid_score[1][5] +
              mid_score[1][6];

  printf ("중간고사 평균 : %6.4f \n", mid_num / 7.0);
  printf ("기말고사 평균 : %6.4f \n", last_num / 7.0);

  return 0;
}
