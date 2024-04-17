#include <stdio.h>
#define N 524288
int t[N * 2];


int max(int x, int y) {
	return x < y ? y : x;
}


int query(int l, int r) {
	if (l < 0) {
		l = 0;
	}
	if (r > N) {
		r = N;
	}
	int res = 0;
	for (l += N, r += N; l < r; l /= 2, r /= 2) {
		if (l & 1) 
			res = max(res, t[l++]);
		if (r & 1)
			res = max(res, t[--r]);
	}

	return res;
}

void upd(int x, int v) {
	x += N;
	while (x) {
		t[x] = max(t[x], v);
		x /= 2;
	}
}


int main() {
	int n, D;
	scanf("%d %d", &n, &D);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int val = query(x - D, x + D + 1) + 1;
		upd(x, val);

		// printf("%d %d", x, val);
	}

	printf("%d\n", t[1]);
}