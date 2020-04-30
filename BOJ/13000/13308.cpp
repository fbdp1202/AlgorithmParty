// baekjoon 13308 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using PP = pair<ll, P>;

const int MAX_N=2501;
const int MAX_M=4001;
const int MAX_C=2501;
const ll MAX_INF=(1LL<<60);

int N,M;
int cost[MAX_N];
bool visited[MAX_N][MAX_C];
ll dist[MAX_N][MAX_C];
vector<P> adj[MAX_N];

ll Dikstra() {
	priority_queue<PP, vector<PP>, greater<PP>> PQ;
	PQ.push(PP(0,P(cost[0],0)));
	for (int i=0; i<MAX_N; i++)
		for (int j=0; j<MAX_N; j++)
			dist[i][j] = MAX_INF;
	dist[0][cost[0]]=0;
	while (!PQ.empty()) {
		int cur_v, cur_w;
		do {
			cur_v = PQ.top().second.second;
			cur_w = PQ.top().second.first;
			PQ.pop();
		} while(!PQ.empty() && visited[cur_v][cur_w]);
		if (visited[cur_v][cur_w]) break;
		visited[cur_v][cur_w]=true;
		for (P &p: adj[cur_v]) {
			int nx = p.first;
			int d = p.second;
			int nw = min(cur_w,cost[nx]);
			if (dist[nx][nw] > dist[cur_v][cur_w] + d*cur_w) {
				dist[nx][nw] = dist[cur_v][cur_w] + d*cur_w;
				PQ.push(PP(dist[nx][nw],P(nw, nx)));
			}
		}
	}

	ll ret = MAX_INF;
	for (int i=0; i<MAX_C; i++)
		ret = min(ret, dist[N-1][i]);
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%d", &cost[i]);

	for (int i=0; i<M; i++) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		u--, v--;
		adj[u].push_back(P(v,d));
		adj[v].push_back(P(u,d));
	}
	printf("%lld\n", Dikstra());
	return 0;
}