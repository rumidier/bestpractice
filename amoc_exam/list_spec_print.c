#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "list_head.h"
#include "list_func_head.h"

void
spec_print (struct linked_list *ptr, int spec_id)
{
  struct linked_list *buf_ptr;
  buf_ptr = malloc (sizeof (struct linked_list));
  buf_ptr -> next_ptr = ptr;

  while (1)
    {
      if (buf_ptr -> id == spec_id)
        {
          fputs ("|----------------------------------|\n", stdout);
          list_print (buf_ptr);
        }

      if (buf_ptr -> next_ptr == NULL)
        {
          break;
        }

      buf_ptr = buf_ptr -> next_ptr;
    }
}
