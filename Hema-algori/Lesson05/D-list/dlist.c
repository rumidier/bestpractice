/************
 * dlist.c
 */

#include <stdlib.h>
#include <string.h>

#include "dlist.h"

/*******************
 * dlist_init
 */

void
dlist_init (DList     *list,
            void      (*destroy) (void *data))
{
  /************
   * 리스트 초기화.
   */

  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;

  return;
}

/*******************************
 * dlist_destroy
 */

void
dlist_destroy (DList *list)
{
  void *data;
  /*************
   * 각 항목 삭제.
   */

  while (dlist_size (list) > 0)
    {
    if (dlist_remove (list, dlist_tail (list), (void **) &data) == 0 && list->destroy != NULL)
      {
        /************************
         * 동적으로 할당된 자료를 해제하기 위해 사용자 정의 함수 호출.
         */
        list->destroy (data);
      }
    }

  /****************************
   * 지금은 아무 연산도 허용되지 않지만 예방책으로 구조체를 지움.
   */

  memset (list, 0, sizeof (DList));

  return;
}

/****************************
 * dlist_ins_next
 */
int
dlist_ins_next (DList *list,
                DListElmt *element,
                const void *data)
{
  DListElmt *new_element;
  /**************************
   * 리스트가 비어 있지 않는 한 element는 NULL이 될 수 없음.
   */

  if (element == NULL && dlist_size (list) != 0)
    return -1;

  /*******************
   * 항목을 위한 메모리 할당.
   */

  if ((new_element = (DListElmt *) malloc (sizeof (DListElmt))) == NULL)
    return -1;

  /*****************
   * 리스트에 새 항목 삽입.
   */

  new_element->data = (void *)data;

  if (dlist_size (list) == 0)
    {
      /*******************
       * 비어 있는 리스트에 삽입 처리
       */
      list->head = new_element;
      list->head->prev = NULL;
      list->head->next = NULL;
      list->tail = new_element;
    }
  else
    {
      /************
       * 비어 있지 않은 리스트에 삽입 처리
       */
      new_element->next = element->next;
      new_element->prev = element;

      if (element->next == NULL)
        list->tail = new_element;
      else
        element->next->prev = new_element;

      element->next = new_element;
    }

  /****************************
   * 삽입된 항목을 반영하기 위해 리스트의 size조정.
   */
  list->size++;
  return 0;
}

/***********
 * dlist_ins_prev
 */
int
dlist_ins_prev (DList        *list,
                DListElmt    *element,
                const void   *data)
{
  DListElmt *new_element;
  /**************
   * 리스트가 비어 있지 않는 한 element는 NULL이 될 수 없음.
   */
  if (element == NULL && dlist_size (list) != 0)
    return -1;

  /**************************
   * 추상 자료형에 의해 관리되는 메모리 할당.
   */

  if ((new_element = (DListElmt *) malloc (sizeof (DListElmt))) == NULL)
    return -1;

  /*******************************
   * 리스트에 새 항목 삽입.
   */

  new_element->data = (void *) data;

  if (dlist_size (list) == 0) {
    /*****************************
     * 비어 있는 리스트에 삽입 처리.
     */

    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  }
  else
    {
      /*********************************
       * 비어 있지 않은 리스트에 삽입 처리.
       */
      new_element->next = element;
      new_element->prev = element->prev;

      if (element->prev == NULL)
        list->head = new_element;
      else
        element->prev->next = new_element;

      element->prev = new_element;
    }

  /**************************************************
   * 삽입된 항목을 반영하기 위해 리스트의 size 조정.
   */
  list->size++;

  return 0;
}

/**********************************************
 * dlist_remove
 */
int
dlist_remove (DList        *list,
              DListElmt    *element,
              void         **data)
{
  /*****************************
   * NULL 항목 또는 빈 리스트에서 삭제 금지.
   */

  if (element == NULL || dlist_size (list) == 0)
    return -1;

  /************************************
   * 리스트에서 항목 삭제.
   */
  *data = element->data;

  if (element == list->head)
    {
      /*************************************
       * 리스트에서 head 항목 삭제 처리.
       */
      list->head = element->next;

      if (list->head == NULL)
        list->tail = NULL;
      else
        element->next->prev = NULL;
    }
  else
    {
      /**************************
       * 리스트에서 head 항목이 아닌 항목 삭제 처리.
       */
      element->prev->next = element->next;

      if (element->next == NULL)
        list->tail = element->prev;
      else
        element->next->prev = element->prev;
    }

  /****************************
   * 추상 자료형에 할당된 메모리 해제.
   */

  free (element);
  /*********************************
   * 삭제된 항목을 반영하기 위해 리스트의 size조정
   */
  list->size--;

  return 0;
}
