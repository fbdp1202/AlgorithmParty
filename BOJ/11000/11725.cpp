// baekjoon 11725 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 100000
vector<int> adj[MAX_N];
int parent[MAX_N];
bool visited[MAX_N];

void dfs(int p) {
	for (auto child : adj[p]) {
		if (!visited[child]) {
			visited[child] = true;
			parent[child] = p;
			dfs(child);
		}
	}
}

int main() {
	int N, u, v;
	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%d%d", &u, &v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	visited[0]=true;
	dfs(0);
	for (int i=1; i<N; i++)
		printf("%d\n", parent[i]+1);

	return 0;
}

/* Reference
#include <cstdio>
#include <vector>
#include <utility>
#include <unistd.h>
#define f(x) {x=0;while(1){if(ptr==buf+sz)syscall(0,0,ptr=buf,sz);if(*ptr<48)break;x=x*10+*ptr++-48;}ptr++;}
#define sz (1<<16)

int a[100001], n;
std::vector<int> g[100001];
void dfs(int s, int p) {
	a[s]=p;
	for(int e : g[s])
		if(e!=p)
			dfs(e, s);
}
int main() {
	char buf[sz],*ptr=buf+sz;
	f(n);
	for(int i=1; i<n; i++) {
		int s, e;
		f(s); f(e);
		g[s].push_back(e);
		g[e].push_back(s);
	}
	dfs(1, 1);
	for(int i=2; i<=n; i++)
		printf("%d\n", a[i]);
}
 */