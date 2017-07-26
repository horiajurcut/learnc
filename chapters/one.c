void PrintSomeRandomString() {
    printf("Hello from foo\t!\n");
}

int FahrenheitToCelsius(int fahr) {
    return (int)(5 * (fahr  - 32) / 9);
}

void SizeOfTypes() {
    printf("Size of char is %d\n", sizeof(char));
    printf("Size of short is %d\n", sizeof(short));
    printf("Size of int is %d\n", sizeof(int));
    printf("Size of float is %d", sizeof(float));
    printf("Size of double is %d", sizeof(double));
}