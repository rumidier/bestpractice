/**********************************************************
 *                    stack.h
**********************************************************/

#ifndef __STACK_H_
#define __STACK_H_

#include <stdlib.h>
#include "list.h"

/**********************************************************
 *
 *             스택을 연결 리스트로 구현
 *
**********************************************************/

typedef List Stack;

/**********************************************************
 *
 *                 공개 인터페이스
 *
**********************************************************/

#define stack_init  list_init
#define stack_destroy list_destroy

int
stack_push (Stack      *stack,
            const void *data);
int
stack_pop (Stack *stack,
           void  **data);

#define stack_peek(stack)  ((stack)->head == NULL ? NULL : (stack)->head->data)
#define stack_size list_size
#endif
