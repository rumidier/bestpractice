#include "list.h"

void
init_line (void)
{
  head = (line *) malloc (sizeof (line));
  tail = (line *) malloc (sizeof (line));

  head->next = tail;
  head->prev = head;
  tail->next = tail;
  tail->prev = head;
}
