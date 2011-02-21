#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int
sachik_cat (char *word);

static void
sachik_yunsan (int sachik, char *word);

int
main (int   argc,
      char *argv[])
{
  char word[256];
  int sachik;

  sachik = 0;

  printf ("수식 입력 : ");

  scanf ("%s", word);
  sachik = sachik_cat (word);


  sachik_yunsan (sachik, word);

  return 0;
}

static int
sachik_cat (char *word)
{
  int check_value;
  int word_len;
  int i;

  check_value = 0;
  word_len = strlen (word);

  for (i = 0; i < word_len; i++)
    {
      if (word[i] == '+')
        check_value = 1;
      else if (word[i] == '-')
        check_value = 2;
      else if (word[i] == '*')
        check_value = 3;
      else if (word[i] == '/')
        check_value = 4;
    }

  return check_value;
}

static void
sachik_yunsan (int sachik, char *word)
{
  int i;
  int st_num;
  int la_num;

  st_num = 0;
  la_num = 0;
  i = 0;

  while (word[i] != '\0')
    {
      if (word[i] >= 48 && word[i] <= 57)
        {
          st_num += (word[i] - 48);
          i++;

          if (word[i] >= 48 && word[i] <= 57)
            {
              st_num *= 10;
            }
        }
      else if (word[i] >= 42 && word[i] <= 47)
        {
          i++;
          while (word[i] != '\0')
            {
              if (word[i] >= 48 && word[i] <= 57)
                {
                  la_num += (word[i] - 48);
                  i++;
                  if (word[i] != '\0')
                    {
                      la_num *= 10;
                    }
                }
            }
        }
      else
        {
          printf ("알수 없는 오류 입니다.\n");
          exit (EXIT_FAILURE);
        }
    }

  switch (sachik)
    {
    case 1:
        {
          printf ("%s = %d\n", word, st_num + la_num);
          break;
        }
    case 2:
        {
          printf ("%s = %d\n", word, st_num - la_num);
          break;
        }
    case 3:
        {
          printf ("%s = %d\n", word, st_num * la_num);
          break;
        }
    case 4:
        {
          printf ("%s = %d\n", word, st_num / la_num);
          break;
        }
    }
}
