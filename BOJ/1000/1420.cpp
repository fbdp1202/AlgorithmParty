// baekjoon 1420 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

const int MAX_N=101;
const int MAX_V=MAX_N*MAX_N*2;
const int MAX_INF=1e9;

struct Edge {
	int to, c, f;
	Edge *dual;
	Edge(): Edge(-1,0){}
	Edge(int to1, int c1):to(to1),c(c1),f(0),dual(nullptr){}
	int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

int N, M, S, E;
char board[MAX_N][MAX_N];
vector<Edge*> adj[MAX_V];
int pv[MAX_V];
Edge *path[MAX_V];

const int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

inline int encode(int x, int y) { return x*M + y; }

void makePath(int u, int v, int uc, int vc) {
	Edge *e1, *e2;
	e1 = new Edge(v, uc);
	e2 = new Edge(u, vc);
	e1->dual = e2;
	e2->dual = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (board[i][j] == '#') continue;
			if (board[i][j] == 'K') S=encode(i,j)*2+1;
			if (board[i][j] == 'H') E=encode(i,j)*2;
			makePath(encode(i,j)*2, encode(i,j)*2+1, 1, 0);
			for (int d=0; d<4; d++) {
				int nx = i + dir[d][0];
				int ny = j + dir[d][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (board[nx][ny] == '#') continue;
				makePath(encode(i, j)*2+1, encode(nx, ny)*2, MAX_INF, 0);
			}
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
				int next = e->to;
				if (e->spare() > 0 && pv[next] == -1) {
					pv[next] = curr;
					path[next] = e;
					Q.push(next);
					if (pv[E] != -1) break;
				}
			}
		}
		if (pv[E] == -1) break;
		if (pv[E] == S) {
			puts("-1");
			return 0;
		}
		for (int i=E; i!=S; i=pv[i])
			path[i]->addFlow(1);
		total++;
	}
	printf("%d\n", total);
	return 0;
}