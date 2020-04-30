// baekjoon 10265 yechan
#include <iostream>
#include <algorithm>
#include <vector>
#define sz(a) ((int)a.size())
using namespace std;
#define MAX_N 1003

int dp[MAX_N];
int visited[MAX_N];
int cycle[MAX_N];
int full[MAX_N];
int child[MAX_N];
int dep[MAX_N];
vector<int> parent[MAX_N];

int N, K;

void full_dfs(int here, int& ecnt, int ccnt) {
	visited[here] = ccnt;
	++ecnt;
	if (visited[child[here]] != ccnt) full_dfs(child[here], ecnt, ccnt);
	for (int i=0; i<(int)parent[here].size(); ++i) {
		if (visited[parent[here][i]] != ccnt) {
			full_dfs(parent[here][i], ecnt, ccnt);
		}
	}
}

int cycle_dfs(int here, int depth, int ccnt) {
	int ret = 0;
	visited[here] = ccnt + N;
	dep[here] = depth;
	if (visited[child[here]] == ccnt + N) ret = max(ret, dep[here] - dep[child[here]] + 1);
	else ret = max(ret, cycle_dfs(child[here], depth + 1, ccnt));

	return ret;
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i=1; i<=N; i++) {
		scanf("%d", &child[i]);
		parent[child[i]].push_back(i);
	}

	int component_cnt=0;
	for (int i=1; i<=N; ++i) {
		if (!visited[i]) {
			++component_cnt;
			int element_cnt = 0;
			full_dfs(i, element_cnt, component_cnt);
			full[component_cnt] = element_cnt;
			cycle[component_cnt] = cycle_dfs(i, 0, component_cnt);
		}
	}

	dp[0]=1;
	for (int i=1; i<=component_cnt; i++) {
		for (int j=K; j>=0; j--) {
			for (int z=cycle[i]; z<=full[i]; z++) {
				if (j-z>=0) dp[j] |= dp[j-z];
			}
		}
	}

	for (int i=K; i>=0; --i) {
		if (dp[i]) {
			printf("%d", i); break;
		}
	}

	return 0;
}

