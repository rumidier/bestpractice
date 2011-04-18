#include <stdio.h>

#include "list_head.h"

void
list_print (struct linked_list *ptr)
{
  printf (" id : %2d\n", ptr -> id);
  printf (" name : %s\n", ptr -> name);
}
