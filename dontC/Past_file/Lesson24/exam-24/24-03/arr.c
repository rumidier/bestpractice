#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int arr[3][4] = {{1}, {2}, {3}};
  /**
   * 문제:
   * *(arr + 2)[3] = 20;
   * *(arr[1] + 3) = 30;
   * *(*(arr + 2) + 1) = 40;
   * *(*arr + 2) = 50;
   * **arr = 70;
   * arr[0] 과 *(arr) 은 같다
   */

  arr[2][3] = 20;
  arr[1][3] = 30;
  arr[2][1] = 40;
  arr[0][2] = 50;
  arr[0][0] = 70;

  /**
   * 정확한 값은 나오지 않는다
   * 문제에 정의된 값을 변경만 한것
   */
  return 0;
}
