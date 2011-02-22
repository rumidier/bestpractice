#include <stdio.h>
#include <string.h>

static char *
partial_str_cmp (char *str, char *sch);

int
main (int   argc,
      char *argv[])
{
  char *str = "She is my best friend";
  char *sch1 = "is";
  char *sch2 = "my";
  char *sch3 = "be";
  char *pos;

  pos = partial_str_cmp (str, sch1);

  if (pos == NULL)
    printf ("찾는 영역 %s이(가) 존재하지 않습니다. \n", sch1);
  else
    printf ("찾는 영역을 포함한 이후의 문자열 : %s \n", pos);

  pos = partial_str_cmp (str, sch2);

  if (pos == NULL)
    printf ("찾는 영역 %s이(가) 존재하지 않습니다. \n", sch2);
  else
    printf ("찾는 영역을 포함한 이후의 문자열 : %s \n", pos);

  pos = partial_str_cmp (str, sch3);

  if (pos == NULL)
    printf ("찾는 영역 %s이(가) 존재하지 않습니다. \n", sch3);
  else
    printf ("찾는 영역을 포함한 이후의 문자열 : %s \n", pos);

  return 0;
}

static char *
partial_str_cmp (char *str, char *sch)
{
  char *return_point;
  int i;
  int str_len;
  int sch_len;

  str_len = strlen (str);
  sch_len = strlen (sch);
  return_point = NULL;

  for (i = 0; i < str_len; i++)
    {
      if (*(str + i) == sch[0])
        {
          if (*(str + i + 1) == sch[1])
            {
                  return_point = str + i;
            }
        }
    }

  return return_point;
}
