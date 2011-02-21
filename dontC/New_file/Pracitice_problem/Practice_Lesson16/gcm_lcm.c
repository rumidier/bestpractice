#include <stdio.h>

static int
simple_gcm (int num1, int num2);

static int
simple_lcm (int num1, int num2);


int
main (int   argc,
      char *argv[])
{
  int num1;
  int num2;
  int gcm;
  int lcm;

  gcm = 0;
  lcm = 0;

  printf ("두개의 자연수를 입력 하시오 : ");
  scanf ("%d %d", &num1, &num2);

  gcm = simple_gcm (num1, num2);
  printf ("최대 공약수 :%d \n", gcm);

  lcm = simple_lcm (num1, num2);
  printf ("최소 공배수 :%d \n", lcm);

  return 0;
}

static int
simple_gcm (int num1, int num2)
{
  int max_num;
  int check_num;
  int i;

  max_num = 1;

  if (num1 > num2)
    check_num = num2;
  else
    check_num = num1;

  for (i = 1; i <= check_num; i++)
    {
      if (!(num1 % i) && !(num2 % i))
        max_num = i;
    }

  return max_num;
}

static int
simple_lcm (int num1, int num2)
{
  int check_num;

  if (num1 > num2)
    check_num = num1;
  else
    check_num = num2;

  while (1)
    {
      if (!(check_num % num1) && !(check_num % num2))
        break;
      check_num++;
    }

  return check_num;
}
