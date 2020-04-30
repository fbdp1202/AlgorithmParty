// baekjoon 10451 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1001;

int T, N, adj[MAX_N], visited[MAX_N];

bool dfs(int curr, int index) {
	if (visited[curr] == index) return true;
	if (visited[curr]) return false;
	visited[curr] = index;
	dfs(adj[curr], index);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		fill(visited, visited+MAX_N, false);
		scanf("%d", &N);
		for (int i=1; i<=N; i++) {
			int x; scanf("%d", &x);
			adj[i] = x;
		}
		int ret = 0;
		for (int i=1; i<=N; i++)
			if (dfs(i, i))
				ret++;
		printf("%d\n", ret);
	}
	return 0;
}
