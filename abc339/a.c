#include <stdio.h>
#include <string.h>

char s[200005];
int main() {

	scanf("%s", s);
	int n = strlen(s);
	int p = n - 1;
	while (s[p] != '.') {
		p -= 1;
	}
	for (int i = p + 1; i < n; i++) {
		printf("%c", s[i]);
	}
}