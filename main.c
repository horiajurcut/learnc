#include "chapters/one.c"

int main() {
    // Call functions from specific chapters

    PrintSomeRandomString();

    int celsius = FahrenheitToCelsius(100);
    printf("%d degrees fahr are equivalent to %d degrees celsius\n", 100, celsius);

    return 0;
}