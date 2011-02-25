#include <stdio.h>
#include <string.h>

static void
lexi_cmp (char *str1, char *str2);
static void
lexi_partial_cmp (char *str1, char *str2, int len);

int
main (int   argc,
      char *argv[])
{
  char str1[] = "It is possible to master C";
  char str2[] = "It is impossible to master C";
  char str3[] = "It is possible to master C in a month or two";

  lexi_cmp (str1, str2);
  lexi_cmp (str1, str3);
  lexi_partial_cmp (str1, str3, 26);

  return 0;
}

static void
lexi_cmp (char *str1, char *str2)
{
  int ret;

  ret = strcmp (str1, str2);

  if (ret == 0)
    printf ("두 문자열은 동일합니다.\n");
  else if (ret < 0)
    printf ("앞서는 문자열 : %s \n", str1);
  else
    printf ("앞서는 문자열 : %s \n", str2);
}

static void
lexi_partial_cmp (char *str1, char *str2, int len)
{
  int ret;

  ret = strncmp (str1, str2, len);

  if (ret == 0)
    printf ("%d번째 문자까지 두 문자열은 동일합니다.\n", len);
  else if (ret < 0)
    printf ("앞서는 문자열 : %s \n", str1);
  else
    printf ("앞서는 문자열 : %s \n", str2);
}
