#include <stdio.h>
#include <stdlib.h>

int str_len (char *num);
int acd_string (const void *, const void *);

int
main (int   argc,
      char *argv[])
{
  int i;
  char *strary[4] = {"Hardware", "Cookie", "Boy", "Power"};

  qsort ((void *)strary, sizeof (strary) / sizeof (char *), sizeof (char *), acd_string);

  for (i = 0; i < 4; i++)
    {
      printf ("%s\n", strary[i]);
    }
  return 0;
}

int
acd_string (const void *num1,
            const void *num2)
{
  char *p1 = *((char **) num1);
  char *p2 = *((char **) num2);

  if (str_len (p1) > str_len (p2))
    return 1;
  else if (str_len (p1) < str_len (p2))
    return -1;
  else
    return 0;
}

int
str_len (char *len)
{
  int string_len;
  string_len = 0;

  while (*len != '\0')
    {
      len++;
      string_len++;
    }

  return string_len;
}
