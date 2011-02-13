#include <stdio.h>

static void
swap_ptr (int **ptr1,
          int **ptr2)
{
  int **num1;
  int **num2;
  int temp;

  num1 = ptr1;
  num2 = ptr2;

  temp = **num1;
  **num1 = **num2;
  **num2 = temp;

}

int
main (int   argc,
      char *argv[])
{
  int num1 = 10;
  int num2 = 20;

  int *ptr1 = &num1;
  int *ptr2 = &num2;

  printf ("Before : ptr1 -> %d, ptr2 -> %d \n", *ptr1, *ptr2);
  swap_ptr (&ptr1, &ptr2);

  printf ("Before : ptr1 -> %d, ptr2 -> %d \n", *ptr1, *ptr2);

  return 0;
}
