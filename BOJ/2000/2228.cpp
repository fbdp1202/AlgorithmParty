// baekjoon 2228 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;
const int MAX_K=51;
const int MIN_INF=-1e9;

int N, M;
int arr[MAX_N];
int dp[MAX_N][MAX_K][2];

int dfs(int here, int num, int pv) {
	if (here == N) return (num == M) ? 0 : MIN_INF;
	int &ret = dp[here][num][pv];
	if (ret != -1) return ret;
	ret = MIN_INF;
	ret = max(ret, dfs(here+1, num, 1));
	ret = max(ret, dfs(here+1, num + pv, 0) + arr[here]);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) 
		scanf("%d", &arr[i]);
	printf("%d\n", dfs(0,0,1));
	return 0;
}