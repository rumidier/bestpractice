#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *
add_string (char *str1,
            char *str2);

int
main (int   argc,
      char *argv[])
{

  char *str1 = "A broken hand works, ";
  char *str2 = "but noste a broken heart";
  char *addstr = add_string (str1, str2);

  printf ("%s + %s \n", str1, str2);
  printf ("   = %s \n", addstr);

  return 0;
}

char *
add_string (char *str1,
            char *str2)
{
  char *add_string_return;
  int str1_len, str2_len;
  int i, j;

  str1_len = strlen (str1);
  str2_len = strlen (str2);

  add_string_return = (char *) malloc (sizeof (char) * (str1_len + str2_len));

  i = 0;

  printf ("strl_len[%d]\n", str1_len);

  for (i = 0; i < str1_len; i++)
    {
      *(add_string_return + i) = *str1++;
    }
  for (j = 0; j < str2_len; j++)
    {
      *(add_string_return + i + j) = *str2++;
    }

  *(add_string_return + (str1_len + str2_len)) = '\n';


  return add_string_return;
}
