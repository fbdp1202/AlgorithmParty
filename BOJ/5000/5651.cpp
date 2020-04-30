// baekjoon 5651 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 301;
const int MAX_INF = 1e9;

typedef pair<int,int> P;

struct Edge{
	int to, c, f;
	Edge *dual;
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
int pv[MAX_N];
Edge *path[MAX_N];
int d[MAX_N][MAX_N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		vector<vector<Edge*>> adj(N+1);
		vector<P> node;
		for (int i=0; i<M; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			u--, v--;
			node.push_back(P(u, v));
			Edge *e1 = new Edge(v, w), *e2 = new Edge(u, 0);
			e1->dual = e2;
			e2->dual = e1;
			adj[u].push_back(e1);
			adj[v].push_back(e2);
		}

		int S=0, E=N-1, total = 0;
		while (1) {
			memset(path, 0, sizeof(path));
			memset(pv, -1, sizeof(pv));
			queue<int> Q;
			Q.push(S);

			while (!Q.empty() && pv[E] == -1) {
				int curr = Q.front();
				Q.pop();
				for (Edge *e: adj[curr]) {
					int next = e->to;
					if (e->spare() && pv[next] == -1) {
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
		}

		memset(d, 0, sizeof(d));

		for (int i=0; i<N; i++) {
			for (Edge *e: adj[i]) {
				if (e->spare()) d[i][e->to] = 1;
				if (e->dual->spare()) d[e->dual->to][i] = 1;
			}
		}

		for (int k=0; k<N; k++)
			for (int i=0; i<N; i++)
				for (int j=0; j<N; j++)
					if (d[i][k] && d[k][j])
						d[i][j] = 1;

		int ret=0;
		for (auto &p: node)
			ret += !d[p.first][p.second];
		printf("%d\n", ret);
	}
	return 0;
}