#include <stdio.h>
#include <time.h>

int
main (int argc, char *argv[])
{
  time_t ct;
  struct tm *now;
  ct = time (NULL);
  now = localtime (&ct);

  printf ("%d년 %d월 %d일 %02d:%02d:%02d\n",
        (now -> tm_year) + 1900,
        (now -> tm_mon) + 1, now -> tm_mday,
        now -> tm_hour, now -> tm_min, now -> tm_sec);

  printf ("%s", ctime (&ct));

  return 0;
}
