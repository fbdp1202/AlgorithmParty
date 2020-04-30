// baekjoon 1983 yechan
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=401;
const int MIN_INF=-1e9;

int N, node, upass, dpass, upsize, downsize;
vector<int> up;
vector<int> down;
vector<vector<vector<int>>> dp;

int dfs(int here, int U, int D) {
	if (here+D == upsize || here+U == downsize) return 0;
	int &ret = dp[here][U][D];
	if (ret != MIN_INF) return ret;
	ret = MIN_INF;
	if (U < upass) ret = max(ret, dfs(here, U+1, D));
	if (D < dpass) ret = max(ret, dfs(here, U, D+1));
	ret = max(ret, dfs(here+1, U, D)+up[here+D]*down[here+U]);
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		if (x) up.push_back(x);
	}
	for (int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		if (x) down.push_back(x);
	}
	upsize = up.size(); downsize = down.size();
	node = min(upsize, downsize);
	upass = N - upsize;
	dpass = N - downsize;
	dp = vector<vector<vector<int>>>(node+1, vector<vector<int>>(upass+1, vector<int>(dpass+1, MIN_INF)));
	printf("%d\n", dfs(0, 0, 0));
	return 0;
}