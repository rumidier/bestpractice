#include <stdio.h>

#define HIT_NUM   5

int
main (int   argc,
      char *argv[])
{
#if HIT_NUM == 5
  puts ("매크로 상수 HIT_NUM은 현재 5입니다.");
#else
  puts ("매크로 상수 HIT_NUM은 현재 5가 아닙니다"):
#endif

  return 0;
}
