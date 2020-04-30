// baekjoon 9525 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N=101;
const int MAX_S=MAX_N*MAX_N;
int N;
char board[MAX_N][MAX_N];
int aBoard[MAX_N][MAX_N];
int bBoard[MAX_N][MAX_N];
vector<int> adj[MAX_S];

int A[MAX_S],B[MAX_S];
bool visited[MAX_S];

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
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	int cnt = 1;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (board[i][j] == 'X') cnt++;
			else aBoard[i][j] = cnt;
		}
		cnt++;
	}
	cnt = 1;
	for (int j=0; j<N; j++) {
		for (int i=0; i<N; i++) {
			if (board[i][j] == 'X') cnt++;
			else bBoard[i][j] = cnt;
		}
		cnt++;
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (!board[i][j]) continue;
			adj[aBoard[i][j]].push_back(bBoard[i][j]);
		}
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int ret = 0;
	for (int i=1; i<MAX_S; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) ret++;
		}
	}
	printf("%d\n", ret);
	return 0;
}