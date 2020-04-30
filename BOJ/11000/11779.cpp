// baekjoon 11779 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

const int MAX_N=1001;
const int MAX_INF=2e9;

int N, M;
vector<pii> adj[MAX_N];
bool visited[MAX_N];
int dist[MAX_N];
int parent[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back(pii(v, c));
	}

	fill(dist, dist+N+1, MAX_INF);
	int s, e;
	scanf("%d%d", &s, &e);
	priority_queue<pii,vector<pii>, greater<pii> > PQ;

	dist[s] = 0;
	PQ.push(pii(0, s));
	while (!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;

		for (int i=0; i<adj[cur].size(); i++) {
			int nx = adj[cur][i].first;
			int c = adj[cur][i].second;
			if (dist[nx] > dist[cur] + c) {
				dist[nx] = dist[cur] + c;
				parent[nx] = cur;
				PQ.push(pii(dist[nx], nx));
			}
		}
	}


	stack<int> ans;
	int idx = e;
	while (1) {
		ans.push(idx);
		if (idx == s) break;
		idx = parent[idx];
	}

	printf("%d\n", dist[e]);
	printf("%d\n", ans.size());
	while (!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}
	puts("");
	return 0;
}