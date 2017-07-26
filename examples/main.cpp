#include <stdio.h>

struct projectile {
	int a;
	int b;
};

int main() {
	projectile p;

	p.a = 1;
	p.b = 2;

	printf("projectile a=%d\n", p.a);
	printf("projectile b=%d\n", p.b);

	return 0;
}