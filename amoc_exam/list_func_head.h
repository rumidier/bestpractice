#ifndef __LIST_FUNC_HEAD_H__
#define __LIST_FUNC_HEAD_H__

typedef struct _linked_list {
  unsigned int id;
  char name[128];
  struct _linked_list *next_ptr;
} Linked_list;

Linked_list *first_ptr;

Linked_list *spec_rut;



void
list_add (int , char *);

void
list_print (Linked_list *);

void
spec_print (Linked_list *, int);

int
list_spec_check (Linked_list *ptr, int spec_id, Linked_list *fir_ptr);

void
list_spec_delete (Linked_list *, int , Linked_list *);

#endif
