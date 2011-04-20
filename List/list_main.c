#include <stdio.h>
#include <stdlib.h>

#include "list_head.h"

int
main (int   argc,
      char *argv[])
{
  //char buf[MAX_LEN];
  int command_value = 0;

  if (argc != 3)
    {
      fputs ("입력 값이 잘못 되었습니다.\n", stdout);
      exit (EXIT_FAILURE);
    }

  command_value = list_cat_command (argc, argv);

  switch (command_value)
    {
    case 1://add
        {
          break;
        }
    case 2://del
        {
          break;
        }
    case 3://change
        {
          break;
        }
    case 4://search
        {
          list_search ();
          break;
        }
    default :
        {
          fputs ("command_value가 잘못 되었습니다.\n", stdout);
          break;
        }
    }

  fputs ("END!!!!!!!!!\n", stdout);

  return 0;
}
