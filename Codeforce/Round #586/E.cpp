#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_N = 200001;
const int MAX_INF = 1e9;

int T, N, M;
ll W[MAX_N];
int disc[MAX_N];

int root[MAX_N];

vector<int> adj[MAX_N];
vector<pair<int,int> > connect;

vector<int> node[MAX_N];
bool visited[MAX_N];

int find(int x) {
	if (root[x] < 0) return x;
	return root[x]=find(root[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) swap(a, b);
	W[a] += W[b];
	W[b] = 0;
	root[a] += root[b];
	root[b] = a;
	return;
}

void dfs(int here, int parent, int count) {
	disc[here] = count;
	for (int i=0; i<adj[here].size(); i++) {
		int there = adj[here][i];
		if (there == here) continue;
		if (there == parent) continue;
		if (!disc[there]) {
			dfs(there, here, count + 1);
			if (disc[there] == count + 1 && root[find(there)] == -1) connect.push_back({here, there});
			else merge(here, there);
		}
		disc[here] = min(disc[here], disc[there]);
	}
}

ll gogo(int here) {
	visited[here] = true;

	ll ret = 0;
	for (int i=0; i<node[here].size(); i++) {
		int nx = node[here][i];
		if (visited[nx]) continue;
		ret = max(ret, gogo(nx));
	}
	return W[here] + ret;
}

int main()
{
	memset(root, -1, sizeof(root));
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++)
		scanf("%lld", &W[i]);

	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int s;
	scanf("%d", &s);

	dfs(s, -1, 1);
	for (int i=0; i<connect.size(); i++) {
		int a = find(connect[i].first);
		int b = find(connect[i].second);
		node[a].push_back(b);
		node[b].push_back(a);
	}

	int sroot = find(s);

	ll ret = gogo(sroot);
	printf("%lld\n", ret);
	return 0;
}