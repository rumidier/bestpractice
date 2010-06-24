#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char line[100];
  int result;
  char operator;
  int value;

  result = 0;

  while (1) {
    printf ("Result: %d\n", result);

    printf ("Enter opoerator and number: ");
    fgets (line, sizeof (line), stdin);
    sscanf (line, "%c %d", &operator, &value);

    if (operator == '+')
      {
        result += value;
      }
    else
      {
        printf ("Unknown operator %c\n", operator);
      }
  }

  return 0;
}
