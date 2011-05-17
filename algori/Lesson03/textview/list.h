#ifndef __LIST_H_
#define __LIST_H_

#include <malloc.h>
#include <stdlib.h>

typedef struct _line {
  char *bug;
  struct _line *prev;
  struct _line *next;
} line;

line *head, *tail;

void
init_line (void);

#endif
