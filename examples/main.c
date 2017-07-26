#include <stdio.h>

typedef struct {
	unsigned char type;
	unsigned short damage;
	unsigned int particles;
} projectile;

typedef struct {
	char unsigned a;
	int b;
	int c;
	short d;
} entity;

int main() {
	printf("Hello World\n");

	projectile Projectiles[40];

	for (int i = 0; i < 40; i++) {
		Projectiles[i].type = i;
		Projectiles[i].damage = i * 50;
		Projectiles[i].particles = i * 5000;
	}

	printf("Here is the size of your projectile %d\n", (int)sizeof(projectile));
	printf("Here is the size of your entity %d\n", (int)sizeof(entity));

	projectile *ProjectilePointer = Projectiles;
	printf("Projectile %d has a damage of %d\n", Projectiles[10].type, Projectiles[10].damage);

	(ProjectilePointer + 10)->damage = 99;
	printf("Projectile %d has a damage of %d\n", Projectiles[10].type, Projectiles[10].damage);

	((projectile *)((char *)ProjectilePointer + 10 * sizeof(projectile)))->damage = 66;
	printf("Projectile %d has a damage of %d\n", Projectiles[10].type, Projectiles[10].damage);

	return 0;
}