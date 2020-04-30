// baekjoon 11006 yechan
#include <cstdio>
using namespace std;

int main() {
	int T, N, M, U;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		U=M*2-N;
		printf("%d %d\n", U, M-U);
	}
	return 0;
}