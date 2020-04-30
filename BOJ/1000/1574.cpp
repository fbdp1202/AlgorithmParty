// baekjoon 1574 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 301;
const int MAX_V = MAX_N*MAX_N;

int R, C, N;
int board[MAX_N][MAX_N];
vector<int> adj[MAX_V];
int A[MAX_N], B[MAX_N];
bool visited[MAX_N];

bool dfs(int here) {
	visited[here] = true;
	for (int &nx: adj[here]) {
		if (B[nx] == -1 || !visited[B[nx]] && dfs(B[nx])) {
			A[here] = nx;
			B[nx] = here;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d%d", &R, &C, &N);
	for (int i=0; i<N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		board[x-1][y-1]=1;
	}

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (board[i][j]) continue;
			adj[i].push_back(j);
		}
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int ret = 0;
	for (int i=0; i<R; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) ret++;
		}
	}
	printf("%d\n", ret);
	return 0;
}