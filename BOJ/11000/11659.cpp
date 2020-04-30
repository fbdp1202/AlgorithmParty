// baekjoon 11659 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int N, M, a, b, tmp[MAX_N+1];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++) {
		scanf("%d", &tmp[i]);
		tmp[i]+=tmp[i-1];
	}
	while (M--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", tmp[b]-tmp[a-1]);
	}
	return 0;
}