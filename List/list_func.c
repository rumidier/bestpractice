#include <string.h>
#include <stdio.h>

#include "list_head.h"

int
list_cat_command (int argc_count, char **argv_str)
{
  int i;

  for (i = 0; i < argc_count; i++)
    {
      if (strcmp (argv_str[i], ADD))
          return 1;
      else if (strcmp (argv_str[i], DEL))
        return 2;
      else if (strcmp (argv_str[i], SEARCH))
        return 3;
      else if (strcmp (argv_str[i], CHANGE))
        return 4;
      else
        return 0;
    }

  return 0;
}

void
list_search ()
{
  FILE *phone_list;

  if ((phone_list = fopen ("linked_phone.csv", "r") == NULL))
    {
      fputs ("파일을 열수 없습니다.\n", stdout);
      exit (EXIT_FAILURE);
    }

  while (1)
    {  
    }
}
