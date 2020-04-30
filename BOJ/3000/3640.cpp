// baekjoon 3640 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1000*2;
const int MAX_INF = 1e9;

struct Edge{
	int to, c, f, d;
	Edge *dual;
	Edge():Edge(-1, 0, 0){}
	Edge(int to1, int c1, int d1):to(to1),c(c1),d(d1),f(0),dual(nullptr){}
	int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

int N, M;
vector<vector<Edge*>> adj;
int pv[MAX_V], dist[MAX_V];
bool inQ[MAX_V];
Edge *path[MAX_V];

int main() {
	while (scanf("%d%d", &N, &M) != -1) {
		const int S = 1;
		const int E = (N-1)*2;
		adj = vector<vector<Edge*>>(MAX_V);
		for (int i=0; i<N; i++) {
			Edge *e1, *e2;
			e1 = new Edge(i*2+1,1,0);
			e2 = new Edge(i*2,0,0);
			e1->dual = e2;
			e2->dual = e1;
			adj[i*2].push_back(e1);
			adj[i*2+1].push_back(e2);
		}

		for (int i=0; i<M; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			a--, b--;
			Edge *e1, *e2;
			e1 = new Edge(b*2, 1, c);
			e2 = new Edge(a*2+1, 0, -c);
			e1->dual = e2;
			e2->dual = e1;
			adj[a*2+1].push_back(e1);
			adj[b*2].push_back(e2);
		}
		int ret = 0;
		for (int t=0; t<2; t++) {
			memset(inQ, 0, sizeof(inQ));
			memset(pv, -1, sizeof(pv));
			memset(path, 0, sizeof(path));
			fill(dist, dist+MAX_V, MAX_INF);
			queue<int> Q;

			dist[S] = 0;
			inQ[S] = true;
			Q.push(S);

			while (!Q.empty()) {
				int curr = Q.front();
				Q.pop();
				inQ[curr] = false;
				for (Edge *e: adj[curr]) {
					int next = e->to;
					int d = e->d;
					if (e->spare() > 0 && dist[next] > dist[curr] + d) {
						dist[next] = dist[curr] + d;
						pv[next] = curr;
						path[next] = e;
						if (!inQ[next]) {
							Q.push(next);
							inQ[next] = true;
						}
					}
				}
			}
			if (pv[E] == -1) break;

			for (int i=E; i!=S; i=pv[i]) {
				ret += path[i]->d;
				path[i]->addFlow(1);
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}