// baekjoon 11134 yechan
#include <cstdio>

int T, N, C;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &C);
		printf("%d\n", (N+C-1)/C);
	}
	return 0;
}