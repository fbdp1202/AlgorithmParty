// baekjoon 11495 yechan
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int MAX_INF=1e9;
const int MAX_N=51;
const int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

struct Edge {
	int to, c, f;
	Edge *dual;
	Edge():Edge(-1,0){}
	Edge(int to1, int c1):to(to1), c(c1), f(0), dual(nullptr){}
	
	int spare() {
		return c - f;
	}

	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

int T;
int N, M;
int board[MAX_N][MAX_N];
vector<vector<Edge*>> adj;

int pv[MAX_N*MAX_N];
Edge *path[MAX_N*MAX_N];

inline int encode(int x, int y) { return x*M + y; }
inline pair<int,int> decode(int code) { return make_pair(code/M, code%M); }

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		adj = vector<vector<Edge*>>(N*M+2);
		int S = N*M, E = N*M+1;
		int sum = 0, total = 0;

		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				scanf("%d", &board[i][j]);
				sum += board[i][j];
			}
		}

		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if ((i+j)%2 == 0) {
					Edge *e1, *e2;
					e1 = new Edge(encode(i,j), board[i][j]);
					e2 = new Edge(S, 0);
					e1->dual = e2;
					e2->dual = e1;
					adj[S].push_back(e1);
					adj[encode(i,j)].push_back(e2);
					for (int d=0; d<4; d++) {
						int nx = i + dir[d][0];
						int ny = j + dir[d][1];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						Edge *e3, *e4;
						e3 = new Edge(encode(nx, ny), MAX_INF);
						e4 = new Edge(encode(i, j), 0);
						e3->dual = e4;
						e4->dual = e3;
						adj[encode(i, j)].push_back(e3);
						adj[encode(nx, ny)].push_back(e4);
					}
				} else {
					Edge *e1, *e2;
					e1 = new Edge(E, board[i][j]);
					e2 = new Edge(encode(i, j), 0);
					e1->dual = e2;
					e2->dual = e1;
					adj[encode(i,j)].push_back(e1);
					adj[E].push_back(e2);
				}
			}
		}

		while (1) {
			memset(pv, -1, sizeof(pv));
			memset(path, 0, sizeof(board));
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
		printf("%d\n", sum-total);
	}
}