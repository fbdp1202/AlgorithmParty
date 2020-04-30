// baekjoon 2316 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 401*2;
const int MAX_INF = 1e9;

struct Edge{
	int to, c, f;
	Edge* dual;
	Edge(): Edge(-1, 0){}
	Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}

	int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

int N, M;
vector<Edge*> adj[MAX_N];
int pv[MAX_N];
Edge* path[MAX_N];

int main() {
	scanf("%d%d", &N, &M);

	for (int i=0; i<N; i++) {
		int u = i*2, v = u+1;
		Edge *e1 = new Edge(v, 1), *e2 = new Edge(u, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		Edge *e1, *e2;
		e1 = new Edge(v*2, 1); e2 = new Edge(u*2+1, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[u*2+1].push_back(e1);
		adj[v*2].push_back(e2);

		e1 = new Edge(u*2, 1); e2 = new Edge(v*2+1, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[v*2+1].push_back(e1);
		adj[u*2].push_back(e2);
	}

	int total = 0, S = 1, E = 2;
	while (1) {
		memset(pv, -1, sizeof(pv));
		memset(path, 0, sizeof(path));

		queue<int> Q;
		Q.push(S);

		while (!Q.empty() && pv[E] == -1) {
			int curr = Q.front();
			Q.pop();

			for (Edge *e: adj[curr]) {
				int next = e->to;
				if (e->spare() > 0 && pv[next] == -1) {
					Q.push(next);
					pv[next] = curr;
					path[next] = e;
					if (next == E) break;
				}
			}
		}
		if (pv[E] == -1) break;

		int flow = MAX_INF;
		for (int i=E; i!=S; i=pv[i])
			flow = min(flow, path[i]->spare());
		for (int i=E; i!=S; i=pv[i])
			path[i]->addFlow(flow);
		total += flow;
	}
	printf("%d\n", total);
	return 0;
}