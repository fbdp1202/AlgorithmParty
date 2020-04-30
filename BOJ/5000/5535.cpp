// baekjoon 5535 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const int MIN_INF=-1e9;
const int MAX_N=201;
const int MAX_D=201;
const int MAX_C=101;

int D, N;
int tmp[MAX_N];
pair<int,int> durable[MAX_N];
int charm[MAX_N];
vector<int> adj[MAX_N];

int dp[MAX_D][MAX_C];

int dfs(int here, int pv=-1) {
	if (here == D) return 0;

	if (pv != -1) {
		int &ret = dp[here][pv];
		if (ret != -1) return ret;
		ret = MIN_INF;
		for (int &curr: adj[here])
			ret = max(ret, dfs(here+1, charm[curr])+abs(charm[curr]-pv));
		return ret;
	}
	int ret = MIN_INF;
	for (int &curr: adj[here])
		ret = max(ret, dfs(here+1, charm[curr]));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &D, &N);
	for (int i=0; i<D; i++)
		scanf("%d", &tmp[i]);

	for (int i=0; i<N; i++)
		scanf("%d%d%d", &durable[i].first, &durable[i].second, &charm[i]);

	for (int i=0; i<D; i++)
		for (int j=0; j<N; j++)
			if (durable[j].first <= tmp[i] && tmp[i] <= durable[j].second)
				adj[i].push_back(j);

	printf("%d\n", dfs(0));
	return 0;
}