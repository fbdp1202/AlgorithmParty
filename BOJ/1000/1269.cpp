// baekjoon 1269 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 200000

int N, M, cnt, A[MAXN];
int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);
	sort(A, A+N);
	for (int i=0; i<M; i++) {
		int x; scanf("%d", &x);
		int idx = lower_bound(A, A+N, x) - A;
		if (0 <= idx && idx < N && A[idx] == x) cnt++;
	}
	printf("%d\n", N+M-2*cnt);
	return 0;
}