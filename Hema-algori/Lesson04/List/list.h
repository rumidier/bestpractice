/*
 * list.h
 */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/*
 * 연결 리스트 항목들의 구조체 정의.
 */

typedef struct ListElmt_ {
  void                 *data;
  struct ListElmt_     *next;
} ListElmt;

/*
 * 연결 리스트 구조체 정의.
 */

typedef struct List_ {
  int       size;
  int       (*match) (const void *key1, const void *key2);
  void      (*destroy) (void *data);

  ListElmt  *head;
  ListElmt  *tail;
} List;

List *fir_list;
ListElmt *fir_element;

/*
 * frames.h
 */
int alloc_frame (List *frames);
int free_frame (List *frames, int frame_number);

/*
 * 공개 인터페이스
 */


void list_init (List *list, void (*destroy)(void *data));
void list_destroy (List *list);
int list_ins_next (List *list, ListElmt *element, const void *data);
int list_rem_next (List *list, ListElmt *element, void **data);
#define list_size(list) ((list) -> size)
#define list_head(list) ((list) -> head)
#define list_tail(list) ((list) -> tail)

#define list_is_head(list, element) ((element) == (list) -> head ? 1 : 0)
#define list_is_tail(element) ((element) -> next == NULL ? 1 : 0)
#define list_data(element) ((element) -> data)
#define list_next(element) ((element) -> next)

#endif
