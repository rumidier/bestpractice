#include <stdio.h>

#define MAX 10

/*****
 * init_array_1 -- 배열을 0으로 초기화함
 *
 * 매개변수
 *        data -- 0으로 초기화할 배열
*****/

void
init_array_1 (int data[])
{
  int index;

  for (index = 0; index < MAX; ++index) {
    data [index] = 0;
  }
}

/*****
 * init_array_2 -- 배열 원소를 0으로 초기화함
 *
 * 매개변수
 *      data -- 0으로 초기화할 배열
*****/

void
init_array_2 (int *data_ptr)
{
  int index;

  for (index = 0; index < MAX; ++index) {
    *(data_ptr + index) = 0;
  }
}

int
main (int argc, char *argv[])
{
  int array [MAX];

  void init_array_1 ();
  void init_array_2 ();

  /* 배열을 초기화 하는 첫째 방법 */
  init_array_1 (array);

  /* 배열을 초기화 하는 둘째 방법 */
  init_array_1 (&array [0]);

  /* 작동은 하지만 컴파일러 경고 발생 */
  init_array_1 (&array);

  /* 첫째 방법과 비슷하지만 */
  /* 호출한 한수가 틀리다. */
  init_array_2 (array);

  return 0;
}
