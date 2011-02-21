#include <stdio.h>
#include <string.h>
#include <malloc.h>

static char *
add_str (char *str1, char *str2);

int
main (int   argc,
      char *argv[])
{
  char *str1 = "A broken hand works, ";
  char *str2 = "buf not a broken heart.";
  char *add_str = add_str (str1, str2);

  printf ("%s + %s \n", str1, str2);
  printf ("   = %s \n", add_str);

  return 0;
}

static char *
add_str (char *str1, char *str2)
{
  char *full_str = NULL;
  int str1_len;
  int str2_len;

  str1_len = strlen (


  return ;
}
