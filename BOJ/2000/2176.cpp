// baekjoon 2176 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=1001;
const int MAX_INF=1e9;
const int S=1;
const int E=2;

int N, M;
vector<P> adj[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];
int dp[MAX_N];

int dfs(int here) {
	if (here == E) return 1;
	int &ret = dp[here];
	if (ret != -1) return ret;
	ret = 0;
	for (P &p: adj[here]) {
		int nx = p.first;
		if (dist[here] > dist[nx]) ret += dfs(nx);
	}

	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		adj[A].push_back(P(B, C));
		adj[B].push_back(P(A, C));
	}
	fill(dist, dist+N+1, MAX_INF);
	priority_queue<P,vector<P>,greater<P>> PQ;

	dist[E]=0;
	PQ.push(P(0, E));
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);
		if (visited[curr]) break;
		visited[curr]=true;

		for (P &p :adj[curr]) {
			int nx = p.first;
			int w = p.second;
			if (dist[nx] > dist[curr] + w) {
				dist[nx] = dist[curr] + w;
				PQ.push(P(dist[nx], nx));
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(S));
	return 0;
}