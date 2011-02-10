#include <stdio.h>
#include <string.h>

int main()
{
  char str[50] = "This is Example String.";
  char *token = NULL;
  char *separator = " ";

  token = strtok(str, separator);
  printf("%s\n", token);
  while ((token = strtok(NULL, separator)) != NULL)
    {
      printf("%s\n", token);
    }
  return 0;
}
