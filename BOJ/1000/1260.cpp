// baekjoon 1260 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;

int N, M, V;
vector<int> adj[MAX_N];
bool visited[MAX_N];
vector<int> ret[2];

void dfs(int here) {
	visited[here] = true;
	ret[0].push_back(here);
	for (int next: adj[here]) {
		if (visited[next]) continue;
		dfs(next);
	}
}


void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		ret[1].push_back(curr);
		for (int next: adj[curr]) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &V);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i=0; i<N; i++)
		sort(adj[i].begin(), adj[i].end());

	dfs(V);
	memset(visited, 0, sizeof(visited));
	bfs(V);
	for (int ans: ret[0])
		printf("%d ", ans);
	puts("");
	for (int ans: ret[1])
		printf("%d ", ans);
	puts("");
	return 0;
}