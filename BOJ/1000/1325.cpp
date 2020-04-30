// baekjoon 1325 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=10001;
const int MAX_M=100001;

int N, M;
vector<int> adj[MAX_N];
bool visited[MAX_N];

int dfs(int here) {
	visited[here] = true;
	int ret = 1;
	for (int nx: adj[here])
		if (!visited[nx])
			ret += dfs(nx);
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[v].push_back(u);
	}

	int maxV = 0;
	vector<int> ans;
	for (int i=1; i<=N; i++) {
		memset(visited, 0, sizeof(visited));
		int tmp = dfs(i);
		if (tmp > maxV) ans.clear(), maxV = tmp;
		if (tmp == maxV) ans.push_back(i);
	}
	for (int p: ans) printf("%d ", p);
	puts("");
	return 0;
}