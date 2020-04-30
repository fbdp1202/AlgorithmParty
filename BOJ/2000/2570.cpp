// baekjoon 2570 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=101;
const int MAX_V=MAX_N*MAX_N;

int N, M;
int board[MAX_N][MAX_N];
int aBoard[MAX_N][MAX_N];
int bBoard[MAX_N][MAX_N];
vector<int> adj[MAX_V];
bool visited[MAX_V];
int A[MAX_V], B[MAX_V];

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
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		board[x-1][y-1] = 1;
	}

	int cnt = 1;
	for (int i=0; i<N*2; i++) {
		for (int j=0; j<=i; j++) {
			if (i-j >= N) continue;
			if (board[i-j][j]) cnt++;
			else aBoard[i-j][j]=cnt;
		}
		cnt++;
	}

	cnt = 1;
	for (int i=-N; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (i+j >= N || i+j < 0) continue;
			if (board[i+j][j]) cnt++;
			else bBoard[i+j][j]=cnt;
		}
		cnt++;
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (board[i][j]) continue;
			adj[aBoard[i][j]].push_back(bBoard[i][j]);
		}
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int ret = 0;
	for (int i=0; i<MAX_V; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) ret++;
		}
	}
	printf("%d\n", ret);
	return 0;
}