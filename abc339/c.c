#include <stdio.h>

int main() {
	long long cur = 0;
	long long ans = 0;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cur += x;
		if (cur < ans) {
			ans = cur;
		}
	}

	printf("%lld\n", cur - ans);
}