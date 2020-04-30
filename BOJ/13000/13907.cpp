// baekjoon 13907 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<int,P>;

const int MAX_INF=1e9;
const int MAX_N=1001;

int N, M, K;
vector<P> adj[MAX_N];

int S, D;
int dist[MAX_N][MAX_N]; // (here, numVertex)
bool visited[MAX_N][MAX_N];

int Dijkstra() {
	priority_queue<PP, vector<PP>, greater<PP>> PQ;
	PQ.push(PP(0, P(0, S)));
	dist[S][0]=0;
	while (!PQ.empty()) {
		int cur_len, cur_x;
		do {
			cur_len = PQ.top().second.first;
			cur_x = PQ.top().second.second;
			PQ.pop();
		} while (!PQ.empty() && visited[cur_x][cur_len]);
		if (visited[cur_x][cur_len]) break;
		visited[cur_x][cur_len] = true;

		for (P &p: adj[cur_x]) {
			int nx = p.first;
			int w = p.second;
			int nlen = cur_len + 1;
			if (nlen >= MAX_N) continue;
			if (dist[nx][nlen] > dist[cur_x][cur_len] + w) {
				dist[nx][nlen] = dist[cur_x][cur_len] + w;
				PQ.push(PP(dist[nx][nlen], P(nlen, nx)));
			}
		}
	}

	int ans = MAX_INF;
	for (int i=0; i<MAX_N; i++)
		ans = min(ans, dist[D][i]);
	return ans;
}

int main() {
	for (int i=0; i<MAX_N; i++)
		for (int j=0; j<MAX_N; j++)
			dist[i][j] = MAX_INF;

	scanf("%d%d%d", &N, &M, &K);
	scanf("%d%d", &S, &D);
	S--, D--;
	for (int i=0; i<M; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	printf("%d\n", Dijkstra());

	int cost = 0;
	for (int i=0; i<K; i++) {
		int x; scanf("%d", &x);
		cost += x;
		int ans = MAX_INF;
		for (int j=0; j<MAX_N; j++)
			ans = min(ans, dist[D][j] + j*cost);
		printf("%d\n", ans);
	}
	return 0;
}