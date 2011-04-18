#ifndef __LIST_FUNC_HEAD_H__
#define __LIST_FUNC_HEAD_H__

#include "list_head.h"

void
list_add (int , char *);

void
list_print (struct linked_list *);

void
spec_print (struct linked_list *, int);

int
list_spec_check (struct linked_list *ptr, int spec_id, struct linked_list *fir_ptr);

void
list_spec_delete (struct linked_list *, int , struct linked_list *);

#endif
