// baekjoon 3584 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N=10001;
const int MAX_K=15;

int T;

int N;
int parent[MAX_N][MAX_K];
int depth[MAX_N];
bool isnroot[MAX_N];
vector<vector<int> > adj;

void makeTreeByDFS(int here) {
	for (int i=0; i<adj[here].size(); i++) {
		int there = adj[here][i];
		depth[there] = depth[here] + 1;
		parent[there][0] = here;
		makeTreeByDFS(there);
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		memset(isnroot, 0, sizeof(isnroot));
		memset(depth, -1, sizeof(depth));
		memset(parent, -1, sizeof(parent));

		adj = vector<vector<int> >(N);
		for (int i=0; i<N-1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--, v--;
			adj[u].push_back(v);
			isnroot[v] = true;
		}

		int root_idx = 0;
		for (int i=0; i<N; i++)
			if (!isnroot[i])
				root_idx = i;

		makeTreeByDFS(root_idx);

		for (int j=0; j<MAX_K-1; j++)
			for (int i=0; i<N; i++)
				if (parent[i][j] != -1)
					parent[i][j+1] = parent[parent[i][j]][j];

		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;

		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		for (int i=0; diff; i++) {
			if (diff & 1) u = parent[u][i];
			diff /= 2;
		}

		if (u != v) {
			for (int j=MAX_K-1; j>=0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		printf("%d\n", u+1);
	}
	return 0;
}