// baekjoon 7616 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N=11111;
const int MAX_INF=1e9;

struct Edge {
	int to, c, f;
	Edge *dual;
	Edge():Edge(-1, 0){}
	Edge(int to1, int c1):to(to1), c(c1), f(0), dual(nullptr){}
	int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

int T, K, N;
int pv[MAX_N];
Edge *path[MAX_N];


int main() {
	while (1) {
		scanf("%d%d", &K, &N);
		++T;
		if (K == 0) break;
		printf("Case %d:\n", T);
		vector<Edge*> adj[MAX_N];
		for (int i=2; i<N; i++) {
			Edge *e1, *e2;
			e1 = new Edge(i*2+1, 1);
			e2 = new Edge(i*2, 0);
			e1->dual = e2;
			e2->dual = e1;
			adj[i*2].push_back(e1);
			adj[i*2+1].push_back(e2);
		}

		for (int i=0; i<N; i++) {
			while (1) {
				char ws;
				int k;
				scanf("%d%c", &k, &ws);
				k--;
				Edge *e1, *e2;
				e1 = new Edge(k*2, 1);
				e2 = new Edge(i*2+1, 0);
				e1->dual = e2;
				e2->dual = e1;
				adj[i*2+1].push_back(e1);
				adj[k*2].push_back(e2);
				if (ws == '\n') break;
			}
		}

		int S = 1, E = 2;
		bool impossible = false;
		for (int k=0; k<K; k++) {
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
						pv[next] = curr;
						path[next] = e;
						Q.push(next);
						if (next == E) break;
					}
				}
			}
			if (pv[E] == -1) {
				impossible = true;
				break;
			}

			for (int i=E; i!=S; i=pv[i])
				path[i]->addFlow(1);

		}
		if (impossible) puts("Impossible");
		else {
			for (int i=0; i<K; i++) {
				int prev = -2, curr = S;
				while (curr != E) {
					if (prev/2 != curr/2) printf("%d ", curr/2+1);
					prev = curr;
					for (Edge *e: adj[curr]) {
						int next = e->to;
						if (e->f == 1) {
							e->f = 0;
							curr = next;
							break;
						}
					}
				}
				printf("%d\n", E/2+1);
			}
		}
		puts("");
	}
}