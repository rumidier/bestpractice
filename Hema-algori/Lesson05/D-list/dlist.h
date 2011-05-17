/***************
 * dlist.h
 */
#ifndef __DLIST_H_
#define __DLIST_H_

#include <stdlib.h>

/******************
 * 이중 연결 리스트 항목들의 구조체 정의.
 */

typedef struct DListElmt_ {
  void              *data;
  struct DListElmt_ *prev;
  struct DListElmt_ *next;
} DListElmt;

/**************
 * 이중 연결 리스트 구조체 정의.
 */

typedef struct DList_ {
  int         size;
  int         (*match) (const void *key1, const void *key2);
  void        (*destroy) (void *data);
  DListElmt   *head;
  DListElmt   *tail;
} DList;

/**************
 * 공개 인터페이스
 */

void
dlist_init (DList *list,
            void (*destroy) (void *data));
void
dlist_destroy (DList *list);

int
dlist_ins_next (DList      *list,
                DListElmt  *element,
                const void *data);

int
dlist_ins_prev (DList      *list,
                DListElmt  *element,
                const void *data);

int
dlist_remove (DList        *list,
              DListElmt    *element,
              void         **data);

#define dlist_size(list)  ((list)->size)
#define dlist_head(list)  ((list)->head)
#define dlist_tail(list)  ((list)->tail)
#define dlist_is_head(element)  ((element)->prev == NULL ? 1 : 0)
#define dlist_is_tail(element)  ((element)->next == NULL ? 1 : 0)
#define dlist_data(element)     ((element)->data)
#define dlist_next(element)     ((element)->next)
#define dlist_prev(element)     ((element)->prev)

#endif
