#include <stdio.h>
#include <string.h>

  struct linked_list {
    struct linked_list *next_ptr;
    char *data;
  };

  struct linked_list *first_ptr;
  /**
   * find -- 연결 리스트 내 데이터 항목을 찾는 프로그램
   *
   * 매개변수
   *    name -- 연결 리스트에서 찾을 이름
   *
   * 반환값
   *    1 (name을 찾으면)
   *    0 (찾지 못하면)
   */
int fine (char *name)
{
  /* 현재 보고 있는 구조체 */
  struct linked_list *current_ptr;

  current_ptr = first_ptr;

  while ((strcmp (current_ptr -> data, name) != 0) &&
         (current_ptr != NULL))
    current_ptr = (*current_ptr) -> next_ptr;
  /**
   * current_ptr 이 NULL이면, 연결 리스트의 끝이므로
   * 해당 이름을 찾지 못한 것이다.
   */

  return (current_ptr != NULL);
}
