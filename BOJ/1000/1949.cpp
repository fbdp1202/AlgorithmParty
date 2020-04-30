// baekjoon 1949 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 10001

int N, num[MAX_N], result;
bool visited[MAX_N];
vector<int> adj[MAX_N];

int dfs(int root, int state) {
	int ret = 0;
	visited[root]=true;

	for (int next : adj[root]) {
		if (visited[next]) continue;
		if (state) ret += dfs(next, 0);
		else ret += max(dfs(next, 0), dfs(next, 1) + num[next]);
	}
	visited[root]=false;
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &num[i]);

	for (int i=0; i<N-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	printf("%d\n", max(dfs(1, 0), dfs(1, 1) + num[1]));
	return 0;
}