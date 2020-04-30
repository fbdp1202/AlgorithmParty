// baekjoon 1658 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int MAX_M=1001;
const int MAX_N=101;
const int MAX_INF=1e9;

struct Edge{
	int to, c, f;
	Edge *dual;
	Edge():Edge(-1, 0){}
	Edge(int to1, int c1):to(to1),c(c1),f(0),dual(nullptr){}
	int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

int M, N;
int S, E;
int K, B;
int arr[MAX_N];
vector<Edge*> adj[MAX_M*MAX_N];
int pv[MAX_M*MAX_N];
Edge *path[MAX_M*MAX_N];

int main() {
	scanf("%d%d", &M, &N);
	S = 0, E = M*N+N+1;
	for (int i=1; i<=M; i++) {
		int x;
		scanf("%d", &x);
		Edge *e1, *e2;
		e1 = new Edge(i, x);
		e2 = new Edge(0, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[0].push_back(e1);
		adj[i].push_back(e2);
	}

	for (int i=1; i<N; i++) {
		for (int j=1; j<=M; j++) { // j+i*M -> j+(i+1)*M
			int curr = (i-1)*M + j;
			int next = i*M + j;
			Edge *e1, *e2;
			e1 = new Edge(next, MAX_INF);
			e2 = new Edge(curr, 0);
			e1->dual = e2;
			e2->dual = e1;
			adj[curr].push_back(e1);
			adj[next].push_back(e2);
		}
	}

	for (int i=1; i<N; i++) {
		scanf("%d", &K);
		for (int j=0; j<K; j++) 
			scanf("%d", &arr[j]);
		scanf("%d", &B);
		for (int j=0; j<K; j++) {
			for (int k=0; k<K; k++) {
				if (j == k) continue;
				int curr = (i-1)*M + arr[j];
				int next = i*M + arr[k];
				Edge *e1, *e2;
				e1 = new Edge(next, MAX_INF);
				e2 = new Edge(curr, 0);
				e1->dual = e2;
				e2->dual = e1;
				adj[curr].push_back(e1);
				adj[next].push_back(e2);
			}
		}
		for (int j=0; j<K; j++) {
			int curr = (i-1)*M + arr[j];
			int next = N*M + i;
			Edge *e1, *e2;
			e1 = new Edge(next, MAX_INF);
			e2 = new Edge(curr, 0);
			e1->dual = e2;
			e2->dual = e1;
			adj[curr].push_back(e1);
			adj[next].push_back(e2);
		}
		int curr = N*M + i;
		int next = E;
		Edge *e1, *e2;
		e1 = new Edge(next, B);
		e2 = new Edge(curr, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[curr].push_back(e1);
		adj[next].push_back(e2);
	}
	scanf("%d", &K);
	for (int j=0; j<K; j++) 
		scanf("%d", &arr[j]);
	scanf("%d", &B);

	for (int j=0; j<K; j++) {
		int curr = (N-1)*M + arr[j];
		int next = N*M + N;
		Edge *e1, *e2;
		e1 = new Edge(next, MAX_INF);
		e2 = new Edge(curr, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[curr].push_back(e1);
		adj[next].push_back(e2);
	}
	int curr = N*M + N;
	int next = E;
	Edge *e1, *e2;
	e1 = new Edge(next, B);
	e2 = new Edge(curr, 0);
	e1->dual = e2;
	e2->dual = e1;
	adj[curr].push_back(e1);
	adj[next].push_back(e2);

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