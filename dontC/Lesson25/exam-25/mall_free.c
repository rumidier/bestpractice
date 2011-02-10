/**
 * P613 문제 1
 * 예제 25-6을 malloc 과 free 함수를 이용해서 정상적으로 동작할 수 있도록
 * 변경하여라.
 */

#include <stdio.h>
#include <malloc.h>

int *
make_int_array (int len,
                int init)
{
  int *arr;
  int i;

  arr = (int *) malloc (sizeof (int) * len);



  for (i = 0; i < len; i++)
    arr[i] = init;

  return arr;
}


int
main (int   argc,
      char *argv[])
{
  int *arr1;
  int *arr2;
  int i;
  
  arr1 = make_int_array (5, 0);
  arr2 = make_int_array (7, 2);

  for (i = 0; i < 5; i++)
    printf ("%d ", arr1[i]);

  printf ("\n");

  for (i = 0; i < 7; i++)
    printf ("%d ", arr2[i]);

  printf ("\n");

  free (arr1);
  free (arr2);
  return 0;
}
