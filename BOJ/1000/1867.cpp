// baekjoon 1867 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 510

int n, k, u, v, bMatch[MAX_N];
vector<vector<int>> node;
bool visit[MAX_N];

bool dfs(int here) {
	if (visit[here]) return false;

	visit[here] = true;
	for (int there : node[here]) {
		if (!bMatch[there] || dfs(bMatch[there])) {
			bMatch[there] = here;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &k);
	node.resize(n + 1);
	for (int i=0; i<k; i++) {
		scanf("%d %d", &u, &v);
		node[u].push_back(v);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		fill(visit, visit+MAX_N+1, false);
		if (dfs(i)) {
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}