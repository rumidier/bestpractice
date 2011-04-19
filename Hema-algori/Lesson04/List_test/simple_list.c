#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#include "simple_head.h"

int
main (int   argc,
      char *argv[])
{
  node *t;
  init_list ();

  ordered_insert (10);
  ordered_insert (5);
  ordered_insert (8);
  ordered_insert (3);
  ordered_insert (1);
  ordered_insert (7);
  ordered_insert (8);

  printf ("\nInitial Linked list is ");
  print_list (head -> next);

  printf ("\nFinding 4 is %ssuccessful", find_node (4) == tail ? "un" : "");

  t = find_node (5);
  printf ("\nFinding 5 is %ssuccessful", t == tail ? "un" : "");

  printf ("\nInserting 9 after 5");
  insert_after (9, t);
  print_list (head -> next);

  t = find_node (10);
  printf ("\nDeleting next last node");
  delete_next (t);
  print_list (head -> next);

  t = find_node (3);
  printf ("\nDeleting next 3");
  delete_next (t);
  print_list (head -> next);

  printf ("\nInserting 2 before 3");
  insert_node (2, 3);
  print_list (head -> next);

  printf ("\nDeleting node 2");
  if (!delete_node (2))
    printf ("\n deleting 2 is unsucessful");
  print_list (head -> next);

  printf ("\nDeleting node 1");
  delete_node (1);
  print_list (head -> next);

  printf ("\nDeleting all node");
  delete_all ();
  print_list (head -> next);

  return 0;
}
