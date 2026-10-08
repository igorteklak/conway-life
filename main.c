#include <stdio.h>
#include "life.h"

void dump_field(int field[HEIGHT][WIDTH])
{
	for (int r = 0; r < HEIGHT; r++) {
		for (int c = 0; c < WIDTH; c++)
			putchar(field[r][c] ? '#' : '.');
		putchar('\n');
	}
	putchar('\n');
}

int main(void)
{
	int field[HEIGHT][WIDTH] = {0};

	/* A GLIDER */
	field[1][2] = 1;
	field[2][3] = 1;
	field[3][1] = 1;
	field[3][2] = 1;
	field[3][3] = 1;

	for (int gen = 0; gen < GENERATIONS; gen++) {
		printf("Generation %d:\n", gen);
		dump_field(field);
		evolve(field);
	}
	return 0;
}

