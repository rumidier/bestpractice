#include <stdio.h>
#include <string.h>

static int
count_mail (char *str);

static int
count_mail (char *str)
{
  char *ptr_mail;
  char str_mail[] = "hanmail.net";
  int  len;
  int count_num;

  len = strlen (str_mail);
  ptr_mail = str;
  count_num = 0;

  while (1)
    {
      ptr_mail = strstr (ptr_mail, str_mail);

      if (ptr_mail != NULL)
        {
          count_num++;
          ptr_mail++;
        }
      else
        break;
    }
  return count_num;
}

int
main (int   argc,
      char *argv[])
{
  char str[] = "EFE@naver.com, ABA@hanmail.net, LEE12@hanmail.net, UCC01@gmail.com";
  int count;

  printf ("%s\n", str);
  count = count_mail (str);

  printf ("hanmail을 쓰는 친구는 %d명 입니다.\n", count);
  

  return 0;
}
