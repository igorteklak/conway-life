#include <string.h>
#include "life.h"

int count_alive(int field[HEIGHT][WIDTH], int row, int col)
{
	int count = 0;
	for (int dr = -1; dr <= 1; dr++) {
		for (int dc = -1; dc <= 1; dc++) {
			if (dr == 0 && dc == 0)
				continue;
			int r = (row + dr + HEIGHT) % HEIGHT;
			int c = (col + dc + WIDTH) % WIDTH;
			count += field[r][c];
		}
	}
	return count;

}

void evolve(int field[HEIGHT][WIDTH])
{
	int next[HEIGHT][WIDTH];
	for (int r = 0; r < WIDTH; r++) {
		for (int c = 0; c < WIDTH; c++) {
			int n = count_alive(field, r, c);
			next[r][c] = ( n == 3 || (n == 2 && field[r][c]))  ? 1 : 0;
		}
	}
	memcpy(field, next, sizeof(next));
}
