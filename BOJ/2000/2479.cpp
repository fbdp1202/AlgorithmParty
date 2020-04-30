// baekjoon 2479 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <stack>
#include <functional>
using namespace std;
const int MAX_K=1001;
const int MAX_N=31;
const int MAX_INF=1e9;
typedef pair<int, int> P;
int N, K, s, t;
char data[MAX_K][MAX_N];
vector<int> adj[MAX_K];
stack<int> st;
bool visited[MAX_K];
int dist[MAX_K];

bool dfs(int here) {
	st.push(here);
	if (here == s) return true;
	bool flag = false;
	for (int i=0; i<adj[here].size(); i++) {
		int nx = adj[here][i];
		if (dist[nx] == dist[here] - 1)
			flag = dfs(nx);
		if (flag) return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &K, &N);
	for (int i=1; i<=K; i++)
		scanf("%s", data[i]);

	for (int i=1; i<=K; i++) {
		for (int j=i+1; j<=K; j++) {
			int ret = 0;
			for (int k=0; k<N; k++) {
				if (data[i][k] != data[j][k]) ret++;
			}
			if (ret == 1) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	fill(dist, dist+MAX_K, MAX_INF);
	priority_queue<P, vector<P>, greater<P> > PQ;
	scanf("%d %d", &s, &t);
	dist[s] = 0;
	PQ.push(P(0, s));
	while (!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur]=true;
		for (int i=0; i<adj[cur].size(); i++) {
			int nx = adj[cur][i];
			if (dist[nx] > dist[cur] + 1) {
				dist[nx] = dist[cur] + 1;
				PQ.push(P(dist[nx], nx));
			}
		}
	}
	if (dist[t] == MAX_INF) return !printf("-1\n");
	dfs(t);
	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}
	return 0;
}