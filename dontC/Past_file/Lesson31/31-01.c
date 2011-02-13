#include <stdio.h>
#include <math.h>

#define   POINT_NUMBER    5

double cal_dist (double x1,
                 double y1,
                 double x2,
                 double y2);

double cal_line_len (double xpos[],
                     double ypos[]);

int
main (int   argc,
      char *argv[])
{
  double line_len;
  double xpos_arr[POINT_NUMBER];
  double ypos_arr[POINT_NUMBER];

  line_len = 0;

  int i;
  for (i = 0; i < POINT_NUMBER; i++)
    {
      printf ("점 %d의 좌표 입력 : ", i + 1);
      scanf ("%lf %lf", &xpos_arr[i], &ypos_arr[i]);
    }

  line_len = cal_line_len (xpos_arr, ypos_arr);
  printf ("라인의 길이 : %g \n", line_len);

  return 0;
}

double
cal_dist (double x1,
                 double y1,
                 double x2,
                 double y2)
{
  double xdist = x1 - x2;
  double ydist = y1 - y2;

  return sqrt (xdist * xdist + ydist * ydist);
}

double
cal_line_len (double xpos[],
            double ypos[])
{
  double len;
  int i;

  for (i = 0; i < POINT_NUMBER - 1; i++)
    {
      len += cal_dist (xpos[i], ypos[i], xpos[i + 1], ypos[i + 1]);
    }

  return len;
}
