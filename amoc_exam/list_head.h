#ifndef __LIST_HEAD_H__
#define __LIST_HEAD_H__

struct linked_list {
  unsigned int id;
  char name[128];
  struct linked_list *next_ptr;
};

struct linked_list *first_ptr;

struct linked_list *spec_rut;


#endif
