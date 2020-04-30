// baekjoon 2159 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using ll = long long;

const int MAX_N=100001;
const ll MAX_INF = (1LL<<61);

const int dir[5][2] = {{0,0},{-1,0},{0,-1},{1,0},{0,1}};

int N;
P pos[MAX_N];
ll dp[MAX_N][5];

inline int getDist(int x1, int y1, int x2, int y2) {
	return abs(x1-x2)+abs(y1-y2);
}

ll dfs(int here, int d) {
	if (here == N) return 0;

	ll &ret = dp[here][d];
	if (ret != MAX_INF) return ret;

	int cx = pos[here].first + dir[d][0];
	int cy = pos[here].second + dir[d][1];

	for (int nd=0; nd<5; nd++) {
		int nx = pos[here+1].first + dir[nd][0];
		int ny = pos[here+1].second + dir[nd][1];
		ret = min(ret, dfs(here+1, nd) + getDist(cx,cy,nx,ny));
	}
	return ret;
}

int main() {
	for (int i=0; i<MAX_N; i++)
		for (int j=0; j<5; j++)
			dp[i][j] = MAX_INF;

	scanf("%d", &N);
	scanf("%d%d", &pos[0].first, &pos[0].second);
	for (int i=1; i<=N; i++)
		scanf("%d%d", &pos[i].first, &pos[i].second);
	printf("%lld\n", dfs(0,0));
	return 0;
}