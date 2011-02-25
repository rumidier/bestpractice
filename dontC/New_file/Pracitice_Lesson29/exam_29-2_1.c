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

int
main (int   argc,
      char *argv[])
{
  char str1[20] = "Your name is ";
  char str2[20];
  int str1_len;
  int str2_len;
  int full_len;

  str1_len = cat_str_len (str1);
  full_len = sizeof (str1) / sizeof (char);

  while (1)
    {
      printf ("이름을 입력하세요 : ");
      gets (str2);

      str2_len = cat_str_len (str2);
      if ((str1_len + str2_len) <= full_len)
        {
          strcat (str1, str2);
          break;
        }

      printf ("입력 길이가 적당하지 않습니다.\n");
    }

  puts (str1);

  return 0;
}
