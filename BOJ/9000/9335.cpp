// baekjoon 9335 yechan
#include <cstdio>
#include <algorithmo>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 21

int T, N, ans=987654321;
bool adj[MAX_N][MAX_N];
bool visited[MAX_N];

int backtracking(int curr, int state) {
	int ans = 0;
	// 홍보
	for (int i=1; i<=N; i++) {
		if (adj[curr][i]) {
			ans = min(backtracking(i, 1)) + 1;
			
		}
	}

	if (!state) {

	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(adj, 0, sizeof(adj));
		scanf("%d", &N);
		for (int i=1; i<=N; i++) {
			int x; scanf("%d", &x);
			for (int j=0; j<x; j++) {
				int y; scanf("%d", &y);
				adj[i][j]=true;
			}
		}

	}
	return 0;
}