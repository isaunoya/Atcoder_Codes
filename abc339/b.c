#include <stdio.h>

const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};

int a[100][100];

int main() {
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);

	int x = 0, y = 0, d = -1;
	for (int i = 0; i < n; i++) {
		a[x][y] ^= 1;
		if (a[x][y]) {
			d = (d + 1) % 4;
		} else {
			d = (d + 3) % 4;
		}

		x = (x + h + X[d]) % h;
		y = (y + w + Y[d]) % w;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j]) {
				printf("#");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
}