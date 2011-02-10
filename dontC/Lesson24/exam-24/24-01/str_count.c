#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char *str = "He Is My Best Friend!";
  int de_string;

  de_string = 0;

  while (*str != '\0')
    {
      if (65 <=  *str && *str <= 90)
          {
            de_string++;
          }
      str++;
    }

  printf ("%d\n", de_string);

  return 0;
}
