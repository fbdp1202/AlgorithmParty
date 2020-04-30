// baekjoon 11266 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

const int MAX_V=10001;

int V, E;
vector<int> adj[MAX_V];
int disc[MAX_V], dcnt;
bool visited[MAX_V];
stack<P> S;
vector<int> cutVertex;

int DFS(int curr, int parent=-1) {
	disc[curr] = ++dcnt;
	int ret = disc[curr];

	bool isCutVertex = false;
	int num_child = 0;
	for (int next : adj[curr]) {
		if (disc[next] == 0) {
			num_child++;
			int df = DFS(next, curr);
			if ((parent != -1) && df >= disc[curr]) isCutVertex = true;
			ret = min(ret, df);
		}
		else
			ret = min(ret, disc[next]);
	}

	if (parent == -1) isCutVertex = (num_child > 1);
	if (isCutVertex) cutVertex.push_back(curr);
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
		if (disc[i] == 0) DFS(i);

	printf("%d\n", cutVertex.size());
	sort(cutVertex.begin(), cutVertex.end());
	for (auto &c: cutVertex)
		printf("%d ", c);
	puts("");

	return 0;
}