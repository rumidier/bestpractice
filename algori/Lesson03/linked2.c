#include <stdio.h>
#include <malloc.h>

typedef struct _dnode
{
  int key;
  struct _dnode *prev;
  struct _dnode *next;
} dnode;

dnode *head, *tail;

void
init_dlist (void)
{
  head = (dnode *) malloc (sizeof (dnode));
  tail = (dnode *) malloc (sizeof (dnode));
  head->next = tail;
  head->prev = head;
  tail->next = tail;
  tail->prev = head;
}

dnode *
find_dnode (int k)
{
  dnode *s;
  s = head->next;

  while (s->key != k && s != tail)
    s = s->next;

  return s;
}

int
delete_dnode (int k)
{
  dnode *s;

  s = find_dnode (k);

  if (s != tail)
    {
      s->prev->next = s->next;
      s->next->prev = s->prev;
      free (s);

      return 1;
    }

  return 0;
}

dnode *
insert_dnode (int k,
              int t)
{
  dnode *s;
  dnode *i = NULL;

  s = find_dnode (t);

  if (s != tail)
    {
      i = (dnode *) malloc (sizeof (dnode));
      i->key = k;
      s->prev->next = i;
      i->prev = s->prev;
      s->prev = i;
      i->next = s;
    }

  return i;
}

dnode *
ordered_insert (int k)
{
  dnode *s;
  dnode *i;

  s = head->next;

  while (s->key <= k && s != tail)
    s = s->next;

  i = (dnode *) malloc (sizeof (dnode));
  i->key = k;
  s->prev->next = i;
  i->prev = s->prev;
  s->prev = i;
  i->next = s;

  return i;
}

int
delete_dnode_ptr (dnode *p)
{
  if (p == head || p == tail)
    return 0;
  p->prev->next = p->next;
  p->next->prev = p->prev;

  free (p);

  return 1;
}

dnode *
insert_dnode_ptr (int k,
                  dnode *t)
{
  dnode *i;

  if (t == head)
    return NULL;

  i = (dnode *) malloc (sizeof (dnode));
  i->key = k;
  t->prev->next = i;
  i->prev = t->prev;
  t->prev = i;
  i->next = t;

  return i;
}

void
print_dlist (dnode *p)
{
  printf ("\n");

  while (p != tail)
    {
      printf ("%-8d", p->key);
      p = p->next;
    }
}

void
delete_all (void)
{
  dnode *p;
  dnode *s;

  p = head->next;

  while (p != tail)
    {
      s = p;
      p = p->next;
      free (s);
    }

  head->next = tail;
  tail->prev = head;
}

int
main (int   argc,
      char *argv[])
{
  dnode *t;
  init_dlist ();

  ordered_insert (10);
  ordered_insert (5);
  ordered_insert (8);
  ordered_insert (3);
  ordered_insert (1);
  ordered_insert (7);
  ordered_insert (8);

  printf ("\nInitial Linked list is ");
  print_dlist (head->next);

  printf ("\nFinding 4 is %ssuccessful", find_dnode (4) == tail ? "un" : "");

  t = find_dnode (5);
  printf ("\nFinding 5 is %ssuccessful", t == tail ? "un" : "");

  printf ("\nInserting 7 before 5");
  insert_dnode_ptr (7, t);
  print_dlist (head->next);

  t = find_dnode (3);
  printf ("\nDeleting 3 ");
  delete_dnode_ptr (t);
  print_dlist (head->next);

  printf ("\nInserting node 2 before 10");
  insert_dnode (2, 10);
  print_dlist (head->next);

  printf ("\nDeleting node 2");
  if (!delete_dnode (2))
    printf ("\n deleting 2 is unsuccessful");
  print_dlist (head->next);

  printf ("\nDeleting node 1");
  delete_dnode (1);
  print_dlist (head->next);

  printf ("\nInserting 15 at first");
  insert_dnode_ptr (15, head->next);
  print_dlist (head->next);

  printf ("\nDeleting all node");
  delete_all ();

  print_dlist(head->next);

  return 0;
}
