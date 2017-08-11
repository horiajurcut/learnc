#include "scope.h"
#include <stdio.h>

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline2(void);
void copy2(void);

int external_scope(void)
{
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline2()) > 0) {
    if (len > max) {
      max = len;
      copy2();
    }
  }

  if (max > 0) {
    printf("%s\n", longest);
  } else {
    printf("Nope.\n");
  }

  return 0;
}

int getline2(void)
{
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

void copy2(void)
{
  int i;
  extern char line[];
  extern char longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0') {
    ++i;
  }
}
