#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "list_head.h"
#include "list_func_head.h"

void
list_spec_delete (struct linked_list *start_ptr, int spec_id, struct linked_list *fir_ptr)
{
  struct linked_list *spec_root_ptr;
  spec_root_ptr = malloc (sizeof (struct linked_list));
  struct linked_list *spec_new_ptr;
  spec_new_ptr = malloc (sizeof (struct linked_list));
  struct linked_list *spec_next_ptr;
  spec_next_ptr = malloc (sizeof (struct linked_list));

  spec_new_ptr = start_ptr;

  while (1)
    {
      if (start_ptr -> id == spec_id)
        {
          if (start_ptr -> next_ptr == fir_ptr -> next_ptr)
            {
              spec_root_ptr = fir_ptr -> next_ptr; 
              fir_ptr = spec_root_ptr; //start-list point check

              free (spec_root_ptr);
            }
          else
            {
              spec_next_ptr = start_ptr -> next_ptr;
              spec_new_ptr -> next_ptr = start_ptr -> next_ptr;

              start_ptr = spec_new_ptr;
            }
        }

      if (start_ptr -> next_ptr == NULL)
        {
          break;
        }

      spec_new_ptr = start_ptr;
      start_ptr = start_ptr -> next_ptr;
    }

  start_ptr = fir_ptr;
}
