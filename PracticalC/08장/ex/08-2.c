#include <stdio.h>

int
main (int argc, char *argv[])
{
  float total_r = 0;
  float old_r = 0;
  float new_r = 0;

  while (1) {
    printf ("저항값을 입력하세요(종료는 0) : ");
    scanf ("%f", &new_r);

    if (new_r == 0) {
      printf ("총 저항값을 출력합니다.");
      break;
    }

    total_r = 1/new_r;
    printf ("%f \n", total_r);
  }

  printf ("%f \n", total_r);

  return 0;
}
