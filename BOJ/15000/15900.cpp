// baekjoon 15900 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N=500001;

int N, ret;
vector<int> adj[MAX_N];
bool visited[MAX_N];

void dfs(int here, int depth) {
	visited[here]=true;
	int count = 0;
	for (int i=0; i<adj[here].size(); i++) {
		if (visited[adj[here][i]]) continue;
		count++;
		dfs(adj[here][i], depth+1);
	}
	if (!count) ret += depth;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	if (ret % 2) puts("Yes");
	else puts("No");
	return 0;
}