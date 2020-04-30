// baekjoon 13302 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=101;
const int MAX_INF=2e9;

int N, M;
bool visited[101];
int dp[MAX_N][MAX_N];

int dfs(int here, int cp) {
	if (here >= N) return 0;
	if (visited[here]) return dfs(here+1, cp);
	int &ret = dp[here][cp];
	if (ret != -1) return ret;
	ret = MAX_INF;
	// buy one day
	ret = min(ret, dfs(here+1, cp) + 10000);
	// buy three day
	ret = min(ret, dfs(here+3, cp+1) + 25000);
	// buy five
	ret = min(ret, dfs(here+5, cp+2) + 37000);
	if (cp >= 3) {
		ret = min(ret, dfs(here+1, cp-3));
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int x;
		scanf("%d", &x);
		visited[x-1]=true;
	}
	printf("%d\n",dfs(0, 0));
	return 0;
}