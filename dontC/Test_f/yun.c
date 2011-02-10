#include <stdio.h>

static int
isleap (int num);

static void
print_message (char *message);

int
main (int   argc,
      char *argv[])
{
  int value;

  printf ("2000 년은 ");
  value = isleap (2000);

  if (value == 1)
    print_message ("윤년 입니다");
  else if (value == 0)
    print_message ("윤년이 아닙니다");

  printf ("2012 년은 ");
  value = isleap (2012);

  if (value == 1)
    print_message ("윤년 입니다");
  else
    print_message ("윤년이 아닙니다");

  printf ("2015 년은 ");
  value = isleap (2015);

  if (value == 1)
    print_message ("윤년 입니다");
  else
    print_message ("윤년이 아닙니다");

  return 0;
}

static void
print_message (char *message)
{
  fputs (message, stdout);
  fputc ('\n', stdout);
}

static int
isleap (int num)
{
  int year_value;

  year_value = !(num % 4) && (num % 100);
  year_value = year_value || !(num % 400);

  return year_value;
}
