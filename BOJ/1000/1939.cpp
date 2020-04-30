// baekjoon 1939 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX_N 10001
typedef pair<int, int> P;

int N, M, A, B, C, lo, mid, hi, start, finish, ans;
vector<P> adj[MAX_N];
bool visited[MAX_N];

int dfs(int n) {
	if (visited[n]) return 0;
	if (n == finish) return 1;
	visited[n]=true;

	int tmp = 0;
	for (int i=0; i<adj[n].size(); i++)
		if (!visited[adj[n][i].first] && adj[n][i].second >= mid) {
			tmp = max(tmp, dfs(adj[n][i].first));

	return tmp;
}


int main() {
	scanf("%d %d", &N, &M);

	lo = 987654321;
	for (int i=0; i<M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		adj[A].push_back(P(B, C));
		adj[B].push_back(P(A, C));
		lo = min(lo, C);
		hi = max(hi, C);
	}
	scanf("%d %d", &start, &finish);

	while (lo <= hi) {
		mid = (lo + hi)/2;
		fill(visited, visited+MAX_N, false);
		if (dfs(start))
			lo = mid+1, ans = max(mid, ans);
		else
			hi = mid-1;
	}

	printf("%d\n", ans);
	return 0;
}