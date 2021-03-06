#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "list_func_head.h"

int
list_spec_check (Linked_list *ptr, int spec_id, Linked_list *fir_ptr)
{
  int spec_check = 0;

  while (1)
    {
      if (ptr -> id == spec_id)
        {
          spec_check = 1;
        }

      if (ptr -> next_ptr == NULL)
        {
          break;
        }

      ptr = ptr -> next_ptr;
    }

  ptr = fir_ptr -> next_ptr;

  return spec_check;
}

void
spec_print (Linked_list *ptr, int spec_id)
{
  Linked_list *buf_ptr;
  buf_ptr = ptr;

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

void
list_spec_delete (Linked_list *start_ptr, int spec_id, Linked_list *fir_ptr)
{
  Linked_list *spec_root_ptr;
  Linked_list *spec_new_ptr;
  Linked_list *spec_next_ptr;

  spec_new_ptr = start_ptr;

  while (1)
    {
      if (start_ptr -> id == spec_id)
        {
          if (start_ptr -> id == fir_ptr -> id && !strcmp (start_ptr -> name, fir_ptr -> name) &&
              start_ptr -> next_ptr == fir_ptr -> next_ptr)
            {
              spec_root_ptr = fir_ptr -> next_ptr; 


              printf ("free id [%d]\n", fir_ptr -> id);
              printf ("free name [%s]\n", fir_ptr -> name);

              free (fir_ptr);

              fir_ptr = spec_root_ptr;
              start_ptr = fir_ptr;
            }
          else
            {
              spec_new_ptr -> next_ptr = start_ptr -> next_ptr;

              printf ("free start id [%d]\n", start_ptr -> id);
              printf ("free start name [%s]\n", start_ptr -> name);

              free (start_ptr);

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
  *start_ptr = *fir_ptr;
}
