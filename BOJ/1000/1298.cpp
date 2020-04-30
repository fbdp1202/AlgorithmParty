// baekjoon 1298 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int N, M;
vector<int> adj[MAX_N];
int A[MAX_N], B[MAX_N];
bool visited[MAX_N];

bool dfs(int here) {
	visited[here] = true;
	for (int &next: adj[here]) {
		if (B[next] == -1 || !visited[B[next]] && dfs(B[next])) {
			A[here] = next;
			B[next] = here;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &N, &M);
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
	}

	int ret = 0;
	for (int i=0; i<N; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ret++;
	}
	printf("%d\n", ret);
	return 0;
}