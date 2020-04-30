// baekjoon 11400 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> P;

const int MAX_N=100001;

int V, E;
int disc[MAX_N], dcnt;
vector<int> adj[MAX_N];
vector<P> cutBrige;

int DFS(int here, int parent=-1) {
	disc[here] = ++dcnt;
	int ret = disc[here];

	for (int there: adj[here]) {
		if (there == parent) continue;
		if (disc[there] == 0) {
			int df = DFS(there, here);
			if (df > disc[here]) cutBrige.push_back(P(min(here,there),max(here,there)));
			ret = min(ret, df);
		}
		else
			ret = min(ret, disc[there]);
	}
	return ret;
}

int main() {
	scanf("%d%d", &V, &E);
	for (int i=0; i<E; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i=1; i<=V; i++)
		if (!disc[i]) DFS(i);

	printf("%d\n", cutBrige.size());
	sort(cutBrige.begin(), cutBrige.end());
	for (auto &p: cutBrige)
		printf("%d %d\n", p.first, p.second);
	return 0;
}