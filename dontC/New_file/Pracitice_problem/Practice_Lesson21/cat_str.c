#include <stdio.h>
#include <string.h>

static int
read_str (char str[]);

static int
print_str (char str[]);

int
main (int   argc,
      char *argv[])
{
  char str[30];
  int len;

  printf ("문자열 입력 : ");
  len = read_str (str);
  printf ("입력된 문자열 길이 %d \n", len);

  printf ("입력된 문자열 : ");
  len = print_str (str);
  printf ("\n");
  printf ("출력된 문자열 길이 %d \n", len);

  return 0;
}

static int
read_str (char str[])
{
  int len;

  len = 0;

  fgets (str, 29, stdin);
  len = strlen (str);

  return len - 1;
}

static int
print_str (char str[])
{
  int len;

  len = 0;
  len = strlen (str);

  str[len - 1] = '\0';
  printf ("%s", str);

  return strlen (str);
}
