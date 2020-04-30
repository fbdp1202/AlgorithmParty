// baekjoon 11441 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100001

int N, M, a, b, d[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &d[i]);
		d[i]+=d[i-1];
	}
	scanf("%d", &M);
	while (M--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", d[b]-d[a-1]);
	}
	return 0;
}