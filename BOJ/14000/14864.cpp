// baekjoon 14864 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=100001;
const int MAX_M=1000001;

int N, M, u, v, ans[MAX_N], check[MAX_N];
bool visited[MAX_N];
vector<int> adj[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}

	for (int i=1; i<=N; i++) {
		for (int j=0; j<adj[i].size(); j++)
			check[adj[i][j]]++;
		ans[i] = (adj[i].size() + i) - check[i];
		if (visited[ans[i]]) return !printf("-1\n");
		visited[ans[i]] = true;
	}

	for (int i=1; i<=N; i++) printf("%d\n", ans[i]);

	return 0;
}