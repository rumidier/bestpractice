#include <stdio.h>
#include <string.h>

#include "list.h"

int
main (int   argc,
      char *argv[])
{
  char buf[20] = "asfsdf";
  char buf_2[20] = "아오...";
  List fir;

  list_init (&fir, NULL);
  list_ins_next (&fir, fir_element, buf); 

  printf ("%s\n", fir.head -> data);


  return 0;
}
