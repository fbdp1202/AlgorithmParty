// baekjoon 11022 yechan
#include <cstdio>

int main() {
	int T, A, B;
	scanf("%d", &T);
	for (int i=1; i<=T; i++) {
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d + %d = %d\n", i, A, B,A+B);
	}
	return 0;
}