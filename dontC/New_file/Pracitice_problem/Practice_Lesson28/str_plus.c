#include <stdio.h>
#include <string.h>
#include <malloc.h>

static char *
plus_add_str (char *str1, char *str2);

int
main (int   argc,
      char *argv[])
{
  char *str1 = "A broken hand works, ";
  char *str2 = "buf not a broken heart.";
  char *add_str = plus_add_str (str1, str2);

  printf ("%s + %s \n", str1, str2);
  printf ("   = %s \n", add_str);

  return 0;
}

static char *
plus_add_str (char *str1, char *str2)
{
  char *full_str = NULL;
  int str1_len;
  int str2_len;
  int full_len;

  str1_len = strlen (str1);
  str2_len = strlen (str2);

  full_len = str1_len + str2_len;

  full_str = (char *) realloc (full_str, (full_len + 1) * (sizeof (char)));
  strcpy (full_str, str1);
  strcat (full_str, str2);

  return full_str;
}
