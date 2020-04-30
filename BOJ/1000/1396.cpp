// baekjoon 1396 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using T = tuple<int,int,int>;

const int MAX_N=200001;
const int MAX_K=19;

int N, M, Q;
int root[MAX_N];
int par[MAX_N][MAX_K];
int temp[MAX_N];
int depth[MAX_N];
int sz[MAX_N];
vector<int> adj[MAX_N];
T node[MAX_N];

int find(int x) {
	if (root[x] < 0) return x;
	return root[x] = find(root[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	root[b] = a;
}

void dfs(int curr, int prev) {
	for (int next: adj[curr]) {
		if (next == prev) continue;
		par[next][0] = curr;
		depth[next] = depth[curr] + 1;
		dfs(next, curr);
	}
}

int getlca(int a, int b) {
	if (depth[a] > depth[b])
		swap(a,b);

	int diff = depth[b] - depth[a];
	for (int i=0; diff; i++) {
		if (diff & 1) b = par[b][i];
		diff /= 2;
	}
	if (a == b) return a;

	for (int i=MAX_K-1; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

int main() {
	memset(root, -1, sizeof(root));
	fill(sz, sz+MAX_N, 1);
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		node[i] = T(c, a, b);
	}
	sort(node, node+M);

	for (int i=N+1; i<=N+M; i++) {
		int u,v,w;
		tie(w,u,v) = node[i-N-1];
		if (find(u) == find(v)) continue;
		sz[i] = sz[find(u)] + sz[find(v)];
		temp[i] = w;
		adj[i].push_back(find(u));
		adj[i].push_back(find(v));
		merge(i, u);
		merge(i, v);
	}

	for (int i=N+M; i>N; i--)
		if (!depth[i])
			dfs(i,0);

	for (int j=1; j<MAX_K; j++)
		for (int i=1; i<=N+M; i++)
			par[i][j] = par[par[i][j - 1]][j-1];

	scanf("%d", &Q);
	for (int i=0; i<Q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (find(a) != find(b)) {
			puts("-1");
			continue;
		}
		int lca = getlca(a, b);
		printf("%d %d\n", temp[lca], sz[lca]);
	}

	return 0;
}