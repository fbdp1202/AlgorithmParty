// baekjoon 2606 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 101

int N, M, u, v, cnt;
vector<int> adj[MAX_N];
bool visited[MAX_N];

void dfs(int idx) {
	for (int i=0; i<adj[idx].size(); i++) {
		int x = adj[idx][i];
		if (!visited[x]) {
			visited[x] = true;
			cnt++;
			dfs(x);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	visited[1]=true;
	dfs(1);
	printf("%d\n", cnt);
	return 0;
}