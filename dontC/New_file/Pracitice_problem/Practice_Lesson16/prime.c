#include <stdio.h>

static void
prime_check (int num1, int num2);

int
main (int   argc,
      char *argv[])
{
  int num1;
  int num2;

  printf ("두 개의 정수 입력 : ");
  scanf ("%d %d", &num1, &num2);

  if (num1 >= num2)
    prime_check (num1, num2);
  else
    prime_check (num2, num1);

  return 0;
}

static void
prime_check (int num1, int num2)
{
  int i;
  int check_value;

  check_value = 1;

  printf ("소수: ");

  while (num2 <= num1)
    {
      for (i = 2; i < num2; i++)
        {
          if (!(num2 % i))
            {
              check_value = 0;
              break;
            }
          else
            check_value = 1;
        }
      if (check_value == 1)
        printf ("%d ", num2);
      num2++;
    }
  printf ("\n");
}
