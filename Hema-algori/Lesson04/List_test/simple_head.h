#ifndef SIMPLE_HEAD_H__
#define SIMPLE_HEAD_H__

typedef struct _node
{
  int key;
  struct _node *next;
} node;

node *head;
node *tail;


void init_list (void);

int delete_next (node *);

node *insert_after (int k, node *t);

node *find_node (int k);

int delete_node (int k);

node *insert_node (int t, int k); /* before k, insert t */

node *ordered_insert (int k);

void
print_list (node *t);

node *delete_all (void);

#endif
