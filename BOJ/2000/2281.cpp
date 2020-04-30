// baekjoon 2281 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define SQ(x) ((x)*(x))

typedef long long ll;
const int MAX_N=1001; 
const ll MAX_INF=(1LL<<62);

int N, M, data[MAX_N];
ll dp[MAX_N][MAX_N];

// state: (data_idx)(col_pos), define: data_idx를 col_pos에 적기위한 minimum cost

ll dfs(int idx, int col) {
	if (idx == N) return 0;
	ll &ret = dp[idx][col];
	if (ret != -1) return ret;
	ret = MAX_INF;
	if (data[idx] + col <= M) ret = min(ret, dfs(idx+1, data[idx] + col + 1));
	if (col) ret = min(ret, dfs(idx+1, data[idx] + 1) + SQ(M-col+1));
	return ret;
}


int main()
{
	memset(dp, 0xFF, sizeof(dp));
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) scanf("%d", &data[i]);
	printf("%lld\n", dfs(0, 0));
	return 0;
}