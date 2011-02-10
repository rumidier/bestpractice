#include <stdio.h>
#include <string.h>
/*
int *
invarr (void)
{
  int arr[3] = {1, 2, 3};

  return arr;
}
 * 형식은 맞다 하지만 선언된 arr 배열이 함수 내부에서 선언 되었기 때문에
 * 반환된 주소값은 엉뚱한 주소값을 반환하게 되어서 에러가 난다.
 */

int *
invarr (int *arr)
{
  return arr;
}// 수정된 invarr 함수

int
main (int   argc,
      char *argv[])
{

  int *ptr;
  int i;

  int arr[3] = {1, 2, 3};

  ptr = invarr (arr);

  for (i = 0; i < 3; i++)
    {
      printf ("%d ", *(ptr + i));
    }
  printf ("\n");

  return 0;
}
