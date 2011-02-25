#include <stdio.h>
#include <string.h>

static int
cat_str_len (char *str)
{
  int str_len;
  int i;

  i = 0;
  str_len = 0;

  while (1)
    {
      if (*(str + i) == '\0')
        {
          break;
        }
      else
        {
          i++;
          str_len++;
        }
    }

  return str_len;
}

static void
put_str (char *str1, char *str2, int full_len)
{
  int str1_len;
  int str2_len;
  int len;
  int i;
  int count;
  char *ptr;

  ptr = str1;
  count = 0;

  str1_len = cat_str_len (str1);
  len = sizeof (str1) / sizeof (char);
  str2_len = cat_str_len (str2);

  for (i = str1_len; i < full_len - 1; i++)
    {
      *(ptr + i) = str2[count];

      if (count == str2_len - 1)
        break;
      count++;
    }

  puts (str1);
}

int
main (int   argc,
      char *argv[])
{
  char str1[20] = "Your name is ";
  char str2[20];
  int full_len;

  full_len = sizeof (str1) / sizeof (char);

  printf ("이름을 입력하세요 : ");
  gets (str2);
  put_str (str1, str2, full_len);

  return 0;
}
