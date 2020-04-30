// baekjoon 9550 yechan
#include <cstdio>

int main() {
	int T, N, K, candy, result;
	scanf("%d", &T);
	while (T--) {
		result=0;
		scanf("%d%d", &N, &K);
		for (int i=0; i<N; i++) {
			scanf("%d", &candy);
			result += candy/K;
		}
		printf("%d\n", result);
	}
}