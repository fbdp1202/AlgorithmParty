// baekjoon 13325 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=(1<<21);

int K;
int N, node[MAX_N];
long long ans = 0;

int dfs(int here, int k) {
	if (k == K) return 0;
	int left = dfs(here*2, k+1) + node[here*2];
	int right = dfs(here*2+1, k+1) + node[here*2+1];
	ans += node[here*2] + node[here*2+1];
	ans += abs(left-right);
	return max(left, right);
}

int main()
{
	scanf("%d", &K);
	N = (1<<(K+1)) - 2;
	for (int i=2; i<=N+1; i++) {
		scanf("%d", &node[i]);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}