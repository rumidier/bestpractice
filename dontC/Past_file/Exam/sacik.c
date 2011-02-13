#include <stdio.h>
#include <stdlib.h>

int
main (int   argc,
      char *argv[])
{
  char buf[256], buf2[256];
  int i, j, num1, num2, k;
  char c = 0;

  int count = sizeof (buf) / sizeof (int);

  printf ("수식 입력 : ");
  scanf ("%s", buf);

  num1 = atoi (buf);

  for (i = 0; i < count; i++)
    {
      if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' ||
          buf[i] == '/')
        {
          c = buf[i];

          k = 0;
          for (j = i + 1; j < count; j++)
            {
              buf2[k] = buf[j];
              k++;
            }
        }
    }
  num2 = atoi (buf2);

  if (c == '+')
    printf ("%d %c %d = %d\n", num1, c, num2, (num1 + num2));
  else if (c == '-')
    printf ("%d %c %d = %d\n", num1, c, num2, (num1 - num2));
  else if (c == '*')
    printf ("%d %c %d = %d\n", num1, c, num2, (num1 * num2));
  else  if(c == '/')
    printf ("%d %c %d = %d\n", num1, c, num2, (num1 / num2));

  return 0;
}
