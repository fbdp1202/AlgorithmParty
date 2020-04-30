// baekjoon 2001 yechan
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int N, M, K, jew[100];
vector<P> adj[100];
bool visited[100*(1<<14)];

int BFS() {
	int result = 0;
	queue<int> q;
	visited[0]=true;

	q.push(0);

	while (!q.empty()) {
		int curr = q.front(); q.pop();
		int cnt = curr / (100*(1<<14));
		int node = curr % (100*(1<<14)) / (1<<14);
		int bag = curr % (100*(1<<14)) % (1<<14);

		if (node == 0) result = max(result, cnt);

		if (jew[node] != -1 && !(bag & (1<<jew[node])) ) {
			visited[node*(1<<14)+(1<<jew[node])]=true;
			q.push(curr+(1<<jew[node])+100*(1<<14));
		}

		for (auto &nnode : adj[node]) {
			if (cnt > nnode.second) continue;
			int next = nnode.first*(1<<14)+bag;
			if (!visited[next]) {
				visited[next] = true;
				q.push(cnt*(100*(1<<14))+next);
			}
		}
	}

	return result;
}

int main() {
	fill(jew, jew+100, -1);

	scanf("%d%d%d", &N, &M, &K);

	for (int i=0; i<K; i++) {
		int x;
		scanf("%d", &x);
		jew[x-1] = i;
	}

	for (int i=0; i<M; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u-1].push_back(P(v-1, w));
		adj[v-1].push_back(P(u-1, w));
	}
	printf("%d\n", BFS());
	return 0;
}