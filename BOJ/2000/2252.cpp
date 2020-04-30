// baekjoon 2252 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, u, v;
vector<int> adj[32001];
bool chk[32001];
int indeg[32001];

void dfs(int here) {
	if (--indeg[here] > 0) return;
	printf("%d ", here);
	for (auto &x: adj[here]) dfs(x);
}

int main() {
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		chk[v]=true;
		indeg[v]++;
	}

	for (int i=1; i<=N; i++)
		if (!chk[i]) dfs(i);
}