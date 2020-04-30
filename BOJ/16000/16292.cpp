// baekjoon 16292 yechan
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
typedef pair<int,int> P;

const int MAX_N=20001;
const int MAX_INF=2e9;

int N, M, a, b, t, x;
int dist[3][MAX_N];
bool visited[MAX_N];
vector<P> adj[MAX_N];

void Dijkstra(int idx, int here) {
	fill(dist[idx], dist[idx]+N, MAX_INF);
	memset(visited, 0, sizeof(visited));
	dist[idx][here] = 0;
	priority_queue<P, vector<P>, greater<P> > PQ;
	PQ.push(P(0, here));
	while (!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;
		for (auto& p : adj[cur]) {
			int nx = p.first, d = p.second;
			if (dist[idx][nx] > dist[idx][cur] + d) {
				dist[idx][nx] = dist[idx][cur] + d;
				PQ.push(P(dist[idx][nx], nx));
			}
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d%d%d", &a, &b, &t);
		a--, b--;
		adj[a].push_back(P(b, t));
		adj[b].push_back(P(a, t));
	}

	for (int i=0; i<3; i++) {
		scanf("%d", &x);
		Dijkstra(i, x-1);
	}

	int ret = MAX_INF;
	for (int i=0; i<N; i++)
		ret = min(ret, max(dist[0][i], max(dist[1][i], dist[2][i])));

	printf("%d\n", ret);
	return 0;
}