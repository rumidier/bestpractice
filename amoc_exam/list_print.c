#include <stdio.h>

#include "list_func_head.h"

void
list_print (Linked_list *ptr)
{
  printf (" id : %2d\n", ptr -> id);
  printf (" name : %s\n", ptr -> name);
}
