#include <stdio.h>

#define TIME
#define COUNT   9
#define HIT_NUM 5

int
main (int   argc,
      char *argv[])
{
#ifdef TIME
#if COUNT != && HIT_NUM == 5 // COUNT 7이 아니고 HIT_NUM 이 5이면
  puts ("모두 만족되었군!");
#endif
#endif

  return 0;
}
