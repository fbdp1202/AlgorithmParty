// baekjoon 2501 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, K;
int main() {
	scanf("%d%d", &N, &K);
	for (int i=1; i<=N; i++) {
		if (N%i == 0) K--;
		if (!K) return !printf("%d\n", i);
	}
	puts("0");
	return 0;
}