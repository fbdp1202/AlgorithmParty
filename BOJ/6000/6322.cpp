// baekjoon 6322 yechan
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T = 1;
	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (!a && !b && !c) break;
		printf("Triangle #%d\n", T);
		if (a == -1) {
			if (b >= c) puts("Impossible.");
			else printf("a = %.3lf\n", sqrt(1.f*c*c-1.f*b*b));
		}
		if (b == -1) {
			if (a >= c) puts("Impossible.");
			else printf("b = %.3lf\n", sqrt(1.f*c*c-1.f*a*a));
		}
		if (c == -1) {
			printf("c = %.3lf\n", sqrt(1.f*a*a + 1.f*b*b));
		}
		puts("");
		T++;
	}
	return 0;
}