#include <stdio.h>
#include <string.h>

typedef struct _CALORIE {
  char  name [40];
  float value;
} CALORIE;

int
calregist (CALORIE *, int);
float
calcalc (CALORIE *, int);

int
main (int argc, char *argv[])
{
  CALORIE cal [500] = {
      {"쌀류", 150.0}, {"짜장면", 57.1},
      {"국수", 133.3}, {"우동", 100.0},
      {"소면", 133.3}, {"식빵", 250.0}
  };
  int cal_num = 6;
  int mode = 0;

  printf ("칼로리 계산기\n");
  while (1) {
    printf ("등록은 1, 계산은 2, 종료는 0을 입력하세요 : ");
    scanf ("%d", &mode);

    if (mode == 0)
      break;
    else if (mode == 1)
      cal_num = calregist (cal, cal_num);

    else if (mode == 2)
      printf ("총칼로리: %6.2fkcal\n\n", calcalc (cal, cal_num));
  }

  return 0;
}

int
calregist (CALORIE *pcal, int num)
{
  printf ("식품명을 입력하세요 : ");
  scanf ("%s", (pcal + num) -> name);
  printf ("그 식품의 칼로리를 입력하세요.[kcal/100g] : ");
  scanf ("%f", & (pcal + num) -> value);
  printf ("등록되었습니다.\n\n");
  return num + 1;
}

float
calcalc (CALORIE *pcal, int num)
{
  char name[40];
  float gram;
  float totalcal = 0.0;
  int i;

  printf ("--식품명 일람----------------------------------------\n");
  for (i = 0; i < num; i++)
    printf ("%s\t", (pcal + i) -> name);
  printf ("\n-----------------------------------------------------\n");

  while (1) {
    printf ("식품명 (end를 입력하면 계산합니다.) : ");
    scanf ("%s", name);
    if (strcmp (name, "end") == 0)
      break;
    printf ("그램 수 : ");
    scanf ("%f", &gram);

    for (i = 0; i < num; i++) {
      if (strcmp (name, (pcal + i) -> name) == 0) {
          totalcal += (pcal + i) -> value * gram / 100.0;
          break;
      }
    }
  }
    return totalcal;
}
