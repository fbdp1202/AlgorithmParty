// baekjoon 10319 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAX_N=1000;
const int MAX_S=101;
const int MAX_V=MAX_N*MAX_S+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int MAX_INF = 1e9;

struct Edge{
	int u, v, c, f;
	Edge():Edge(-1, -1, 0){}
	Edge(int u1, int v1, int c1):u(u1),v(v1),c(c1),f(0){}
	int oppo(int s) {
		return (s == u ? v : u);
	}
	int spare(int s) {
		return (s == u ? c-f : f);
	}
	void addFlow(int s, int f1) {
		(s == u ? f += f1 : f -= f1);
	}
};

int pv[MAX_V];
Edge *path[MAX_V];
vector<vector<Edge*>> adj;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, I, G, L, M, init, R, x;
		adj = vector<vector<Edge*>>(MAX_V);
		scanf("%d%d%d%d%d", &N, &I, &G, &L, &M);
		init = MAX_S*(I-1);
		Edge *e = new Edge(S, init, G);
		adj[S].push_back(e);
		adj[init].push_back(e);

		for (int i=0; i<M; i++) {
			scanf("%d", &x); x--;
			for (int j=0; j<=L; j++) {
				int curr = x*MAX_S + j;
				e = new Edge(curr, E, MAX_INF);
				adj[curr].push_back(e);
				adj[E].push_back(e);
			}
		}

		scanf("%d", &R);
		for (int i=0; i<R; i++) {
			int a, b, p, d;
			scanf("%d%d%d%d", &a, &b, &p, &d);
			a--, b--;
			for (int j=0; j+d<=L; j++) {
				int curr = a*MAX_S + j, next = b*MAX_S + j + d;
				e = new Edge(curr, next, p);
				adj[curr].push_back(e);
				adj[next].push_back(e);
			}
		}

		for (int i=0; i<N; i++) {
			for (int j=0; j<L; j++) {
				int curr = i*MAX_S + j, next = curr + 1;
				e = new Edge(curr, next, MAX_INF);
				adj[curr].push_back(e);
				adj[next].push_back(e);
			}
		}

		int total = 0;
		while (1) {
			memset(pv, -1, sizeof(pv));
			memset(path, 0, sizeof(path));
			queue<int> Q;
			Q.push(S);

			while (!Q.empty() && pv[E] == -1) {
				int curr = Q.front();
				Q.pop();
				for (Edge *e: adj[curr]) {
					int next = e->oppo(curr);
					if (e->spare(curr) > 0 && pv[next] == -1) {
						pv[next] = curr;
						path[next] = e;
						Q.push(next);
					}
				}
			}
			if (pv[E] == -1) break;

			int flow = MAX_INF;
			for (int i=E; i!=S; i=pv[i])
				flow = min(flow, path[i]->spare(pv[i]));
			for (int i=E; i!=S; i=pv[i])
				path[i]->addFlow(pv[i], flow);
			total += flow;
		}
		printf("%d\n", total);
	}
}