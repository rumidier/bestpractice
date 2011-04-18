#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "list_head.h"
#include "list_func_head.h"

int
list_spec_check (struct linked_list *ptr, int spec_id, struct linked_list *fir_ptr)
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

