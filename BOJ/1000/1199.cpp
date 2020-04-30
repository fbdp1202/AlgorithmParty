// baekjoon 1199 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 1001

struct Edge{
	int to, cnt;
	Edge *nEdge;
	Edge(){ to=-1, cnt=-1; nEdge=nullptr; }
	Edge(int _to, int _cnt){ to=_to, cnt=_cnt; nEdge=nullptr; }
};

int N, numEdge[MAX_N];
bool visited[MAX_N];
vector<Edge*> adj[MAX_N];

int dfs(int curr) {
	if (visited[curr]) return 0;
	visited[curr] = true;
	int rst = 1;
	for (Edge *e : adj[curr]) {
		rst += dfs(e->to);
	}
	return rst;
}

void Printroot(int curr) {
	for (Edge *e : adj[curr]) {
		if (e->cnt && e->nEdge->cnt) {
			e->cnt--;
			e->nEdge->cnt--;
			Printroot(e->to);
		}
	}
	printf("%d ", curr);
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			int x; scanf("%d", &x);
			if (x && i < j) {
				Edge *u = new Edge(j, x);
				Edge *v = new Edge(i, x);
				u->nEdge = v;
				v->nEdge = u;
				adj[i].push_back(u);
				adj[j].push_back(v);
				numEdge[i] += x;
				numEdge[j] += x;
			}
		}
	}

	for (int i=1; i<=N; i++)
		if (numEdge[i]%2) return !printf("-1\n");

	int comp = 0;
	for (int i=1; i<=N; i++) {
		if (!visited[i]){
			if (dfs(i)) {
				if (comp) return !printf("-1\n");
				comp++;
			}
		}
	}
	Printroot(1);
	return 0;
}