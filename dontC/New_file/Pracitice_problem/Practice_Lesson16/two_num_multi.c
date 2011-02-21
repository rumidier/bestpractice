#include <stdio.h>

static void
multi_print (int num1, int num2);


int
main (int   argc,
      char *argv[])
{
  int a;
  int b;

  printf ("두 개의 정수 입력 : ");
  scanf ("%d %d", &a, &b);

  multi_print (a, b);
  printf ("\n");

  return 0;
}

static void
multi_print (int num1, int num2)
{
  int count;
  int value;

  value = 0;
  count = 1;

  while (1)
    {
      value = num1 * count;

      if (value % num2)
        {
          if (value > 100)
            break;
          printf ("%d ", value);
        }
      count++;
    }
}
