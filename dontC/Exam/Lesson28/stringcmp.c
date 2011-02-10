#include <stdio.h>

static char *
partial_string_cmp (char *str,
                    char *sch1);

int
main (int   argc,
      char *argv[])
{
  char *str = "She is my best friend";
  char *sch1 = "is";
  char *sch2 = "my";
  char *sch3 = "be";
  char *pos;

  pos = partial_string_cmp (str, sch1);
  if (pos == NULL)
    printf ("찾는 영역 %s이(가) 존재하지 않습니다. \n", sch1);
  else
    printf ("찾는 영역을 포함한 이후의 문자열 : %s \n", pos);

  pos = partial_string_cmp (str, sch2);
  if (pos == NULL)
    printf ("찾는 영역 %s이(가) 존재하지 않습니다. \n", sch2);
  else
    printf ("찾는 영역을 포함한 이후의 문자열 : %s \n", pos);

  pos = partial_string_cmp (str, sch3);
  if (pos == NULL)
    printf ("찾는 영역 %s이(가) 존재하지 않습니다. \n", sch3);
  else
    printf ("찾는 영역을 포함한 이후의 문자열 : %s \n", pos);

  return 0;
}

static char *
partial_string_cmp (char *str,
                    char *sch)
{
  char *ptr;
  char *sch_string;

  ptr = str;
  sch_string = sch;

  while (*ptr != '\0')
    {
      if (*ptr == *sch_string)
        {
          if (*(ptr + 1) == *(sch_string + 1))
            {
              return ptr;
              ptr++;
            }
        }
      else
        {
          ptr++;
        }
    }

  return NULL; 
}
