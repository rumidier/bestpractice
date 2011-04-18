#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "list_head.h"

void
list_add (int id, char *name)
{
  struct linked_list *new_item_ptr;

  new_item_ptr = malloc (sizeof (struct linked_list));

  new_item_ptr -> id =  id;
  strcpy (new_item_ptr -> name, name);
  new_item_ptr -> next_ptr = first_ptr;
  first_ptr = new_item_ptr;

}
