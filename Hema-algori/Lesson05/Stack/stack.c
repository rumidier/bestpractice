/*********************************************************
 *
 *                       stack.c
 *
 ********************************************************/

#include <stdlib.h>

#include "list.h"
#include "stack.h"

/*********************************************************
 *
 *                  stack_push
 *
 ********************************************************/

int
stack_push (Stack *stack,
            const void *data)
{
/*********************************************************
 *
 *                  스택에 자료를 push
 *
 ********************************************************/

  return list_ins_next (stack, NULL, data);
}

/*********************************************************
 *
 *                 stack_pop 
 *
 ********************************************************/

int
stack_pop (Stack *stack,
           void **data)
{
/*********************************************************
 *
 *                 스택에서 자료를 pop
 *
 ********************************************************/

  return list_rem_next (stack, NULL, data);
}
