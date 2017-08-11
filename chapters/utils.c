#include "utils.h"
#include <stdio.h>

/* Read a line into a char array and return the length */
int getline1(char line[], int maxline)
{
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  // Last character could be EOF or we could have hit the limit
  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

/* Copy "from" into "to" - assumes "to" is big enough */
void copyline1(char to[], char from[])
{
  int i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
