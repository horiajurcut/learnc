#include "one.h"
#include <stdio.h>

/* Here are some symbolic constants */
#define LOWER 0
#define UPPER 300
#define STEP 20

#define IN 1
#define OUT 0

void PrintSomeRandomString()
{
  printf("\n\n");
  printf("Hello from foo\t!\n");
  printf("\n\n");
}

int FahrenheitToCelsius(int fahr)
{
  /* Integer division truncates */
  return (int)(5 * (fahr - 32) / 9);
}

float FahrenheitToCelsiusFloat(float fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}

void SizeOfTypes()
{
  printf("\n\n");
  printf("Size of char is %zd\n", sizeof(char));
  printf("Size of short is %zd\n", sizeof(short));
  printf("Size of int is %zd\n", sizeof(int));
  printf("Size of long is %zd\n", sizeof(long));
  printf("Size of float is %zd\n", sizeof(float));
  printf("Size of double is %zd\n", sizeof(double));
  printf("\n\n");
}

void PrintSomeFormattedRandomString()
{
  printf("This is the number 56 in hex %8x\n", 56);
}

void PrintTemperatureTable()
{
  int fahr;

  printf("\n\n");
  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
  printf("\n\n");
}

void CopyInputToOutput()
{
  /* We declare c as int so it's big enough to hold EOF */
  int c;

  printf("Type anything you want...\n");
  c = getchar();
  /* EOF on Windows is Ctrl+Z */
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  /* Yes, the terminal is line buffered, don't act so surprised */
}

void CopyInputToOutputOptimal()
{
  int c;

  /* The precedence of != is higher than that of = */
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}

void PrintEndOfFile()
{
  printf("\n\n");
  printf("This is the end. Of file. EOF is %d\n", EOF);
  printf("\n\n");
}

void CountCharacters()
{
  long nc;

  nc = 0;
  while (getchar() != EOF) {
    /* Yes, this does count new line. Dooh. */
    ++nc;
  }
  /* %ld tells printf that the argument is a long integer */
  printf("\n\nYou typed %ld characters. Congrats!\n\n\n", nc);
}

void CountBiggerCharacters()
{
  double nc;

  for (nc = 0; getchar() != EOF; ++nc)
    ;
  /* Yes, printf uses %f for both float and double */
  printf("\n\nYou typed in %.0f bigger characters. Wow!\n\n\n", nc);
}

void CountLines()
{
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF) {
    /* Character between single quotes -> integer value */
    if (c == '\n') {
      ++nl;
    }
  }
  printf("\n\nImpressive! You typed %d lines\n\n\n", nl);
}

void CountWords()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;

    if (c == '\n') {
      ++nl;
    }

    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("\n\n\nLines %d, Words %d, Characters %d\n", nl, nw, nc);
}

void CountDigitsWhiteSpaceAndOthers()
{
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  /* Initialize array elements with 0 */
  for (i = 0; i < 10; i++) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }

  printf("\ndigits = ");
  for (i = 0; i < 10; i++) {
    printf(" %d", ndigit[i]);
  }
  printf(", white space = %d, other = %d\n", nwhite, nother);
}

int power(int base, int n)
{
  int i, p;

  p = 1;
  for (i = 1; i <= n; i++) {
    p = p * base;
  }

  return p;
}

int chapter_one()
{
  char verbose = 0;

  // PrintSomeRandomString();
  // PrintSomeFormattedRandomString();
  // PrintTemperatureTable();
  // SizeOfTypes();
  // CopyInputToOutputOptimal();
  // CopyInputToOutput();
  // CountCharacters();
  // CountBiggerCharacters();
  // CountLines();
  // PrintEndOfFile();
  // CountWords();
  // CountDigitsWhiteSpaceAndOthers();

  printf("\n\n%d to the power %d of is %d\n\n", 3, 5, power(3, 5));

  if (verbose == 1) {
    int celsius = FahrenheitToCelsius(100);
    printf("\n\n%6d degrees fahr are equivalent to %6d degrees celsius\n\n\n", 100, celsius);

    float celsiusFloat = FahrenheitToCelsiusFloat(100.0);
    printf("\n\n%6.2f degrees fahr are equivalent to %6.2f degrees celsius\n\n\n", 100.0,
           celsiusFloat);
  }

  return 0;
}
