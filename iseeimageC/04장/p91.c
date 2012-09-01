#include <stdio.h>
#include <string.h>

int
main (int argc, char *argv[])
{
  char s1[] = "cat", s2[] = "dog";
  char s[20];

  sprintf (s, "I love %s and %s.", s1, s2);
  printf ("%s의 글자 수는 %d\n", s, strlen (s));

  return 0;
}
