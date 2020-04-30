// baekjoon 11377 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;

int N, M, K;
int A[MAX_N*2], B[MAX_N];
bool visited[MAX_N*2];
vector<int> adj[MAX_N*2];

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
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	scanf("%d%d%d", &N, &M, &K);
	for (int i=0; i<N; i++) {
		int W;
		scanf("%d", &W);
		for (int j=0; j<W; j++) {
			int x;
			scanf("%d", &x);
			x--;
			adj[i].push_back(x);
			adj[i+N].push_back(x);
		}
	}

	int ret = 0;
	for (int i=0; i<N; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ret++;
	}

	int cnt = 0;
	for (int i=0; i<N; i++) {
		if (cnt >= K) break;
		memset(visited, 0, sizeof(visited));
		if (dfs(i+N)) cnt++;
	}
	printf("%d\n", ret+cnt);

	return 0;
}