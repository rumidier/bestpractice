#include <stdio.h>
#include <stdlib.h>

int cmpstring (char *str1, char *str2);
int compare (const void *pkey, const void *pvalue);

int
main (int   argc,
      char *argv[])
{
  char *strary[4] = {"Boy", "Cookie", "Hardware", "Power"};
  char *srchstr = "Cookie";
  char **srchresult;

  srchresult = (char **) bsearch (
    (void *) srchstr, strary, sizeof (strary) / sizeof (char *),
    sizeof (char *), compare);

  if (srchresult == NULL)
    printf ("찾는 대상이 존재하지 않습니다. \n");
  else
    printf ("찾는 대상 %s이 저장되어 있는 위치 : %p \n",
            *srchresult, srchresult);

  return 0;
}

int cmpstring (char *str1, char *str2)
{
  while (*str1 != '\0' || *str2 != '\0')
    {
      if (*str1 < *str2)
        {
          return 1;
        }
      else if (*str1 > *str2)
        {
          return -1;
        }
      else
        {
          str1++;
          str2++;
        }
    }

  return 0;
}

int
compare (const void *pkey,
         const void *pvalue)
{
  char *key = (char *)pkey;
  char *value = *((char **) pvalue);

  return cmpstring (key, value);
}
