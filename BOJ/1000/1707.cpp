// baekjoon 1707 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adj;
vector<int> visited;

int cnt;

bool bfs(int start) {
	int component = cnt;
	visited[start] = cnt;
	queue<int> q;
	q.push(start);
	while (q.size()) {
		int qSize = q.size();
		while (qSize--) {
			int curr = q.front(); q.pop();
			for (int next : adj[curr]) {
				if (!visited[next]) {
					visited[next] = cnt+1;
					q.push(next);
				}
				else if (component <= visited[next] && visited[next] != cnt+1) {
					if ((visited[next]-visited[curr])%2 == 1 || (cnt+1-visited[next])%2 == 1) {
						return false;
					}
				}
			}
		}
		cnt++;
	}
	return true;
}

int main() {
	int K, V, E, a, b;
	scanf("%d", &K);
	while (K--) {
		scanf("%d", &V);
		adj = vector<vector<int> >(V+1);
		visited = vector<int>(V+1, 0);
		scanf("%d", &E);
		for (int i=0; i<E; i++) {
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cnt=1;
		bool ret = true;
		for (int i=1; i<=V; i++) {
			if (!visited[i]) {
				ret = bfs(i);
			}
			if (!ret) break;
		}
		if (!ret) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}