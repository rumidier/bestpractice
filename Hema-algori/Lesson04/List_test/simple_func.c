#include <stdlib.h>
#include <malloc.h>

#include "simple_head.h"

void init_list (void)
{
  head = (node *) malloc (sizeof (node));
  tail = (node *) malloc (sizeof (node));
  head -> next = tail;
  tail -> next = tail;
}

/*
 * init_list
 * 초기화 head와 tail를 설정
 * head -> tail && tail -> tail 처음과 끝 을 지정
 */

int delete_next (node *t)
{
  node *s;

  if (t -> next == tail)
    return 0;
  s = t -> next;
  t -> next = t -> next -> next;
  free (s);

  return 1;
}

/*
 * t의 next가 tail (마지막 꼬리, 또는 NULL을 가지고 있는 구조체)라면 0 리턴
 * t -> next 에 지워질 next 주소값을 이전 시키고
 * t의 다음인 s 구조체  free
 */


node *insert_after (int k, node *t)
{
  node *s;
  s = (node *) malloc (sizeof (node));
  s -> key = k;
  s -> next = t -> next;
  t -> next = s;

  return s;
}

/*
 * t번째의 주소값 이후에 저장 하기 위한 함수
 * s라는 임의 구조체를 동적 할당후 key 값 대입
 * s -> next 의 값은 t -> next 값 대입
 * t -> next 는 새로 만들어진 s 의 주소 지정
 */

node *find_node (int k)
{
  node *s;

  s = head -> next;

  while (s -> key != k && s != tail)
    s = s -> next;

  return s;
}

/*
 * 꼬리가 아니고 key 값이 k값과 동일한 지점을 반복해서 찾아
 * 주소값 반환
 */

int delete_node (int k)
{
  node *s;
  node *p;
  p = head;
  s = p -> next;

  while (s -> key != k && s != tail)
    {
      p = p -> next;
      s = p -> next;
    }

  if (s != tail) /* (if find) */
    {
      p -> next = s -> next;
      free (s);

      return 1;
    }

  return 0;
}
/* p는 s 보다 한개의 리스트 뒤에 위치해 있다.
 * 지워야할 s -> key = k 를 찾았다면 s != tail일때
 * p -> next = s -> next (지워지는 s의 다음 리스트주소 대입)
 * free (s)
 */

node *insert_node (int t, int k) /* before k, insert t */
{
  node *s;
  node *p;
  node *r;

  p = head;
  s = p -> next;

  while (s -> key != k && s != tail)
    {
      p = p -> next;
      s = p -> next;
    }

  if (s != tail) /* if find */
    {
      r = (node *) malloc (sizeof (node));
      r -> key = t;
      p -> next = r;
      r -> next = s;
    }

  return p -> next;
}

/*
 * 현재 위치가 꼬리가 아니었을때  원하는 k의값 이전에
 * 새로운 r 동적 할당후 대입
 * p -> r -> s 로 만들어 준다
 */

node *ordered_insert (int k)
{
  node *s;
  node *p;
  node *r;

  p = head;
  s = p -> next;

  while (s -> key <= k && s != tail)
    {
      p = p -> next;
      s = p -> next;
    }

  r = (node *) malloc (sizeof (node));
  r -> key = k;
  p -> next = r;
  r -> next = s;

  return r;
}

/* 리스트는 sort 되 있다고 가정 해야 하며
 * p -> s -> k 로 만들어 준다
 */

void
print_list (node *t)
{
  printf ("\n");

  while (t != tail)
    {
      printf ("%-8d", t -> key);
      t = t -> next;
    }
}
/*
 * head -> print -> tail
 * print 부분만 키 값 출력
 */

node *delete_all (void)
{
  node *s;
  node *t;

  t = head -> next;

  while (t != tail)
    {
      s = t;
      t = t -> next;
      free (s);
    }

  head -> next = tail;

  return head;
}

/* full_free
 */
