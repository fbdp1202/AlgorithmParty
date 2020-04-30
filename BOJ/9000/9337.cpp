// baekjoon 9337 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 21

typedef pair<int, int> P;

int T, N;
char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int BFS(int x, int y) {
	int cnt = 0;

	queue<P> q;
	board[]
	q.push({x*N+y, 0});

}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		// fill board
		for (int i=0; i<N; i++)
			scanf("%s", board[i]);

		memset(visited, 0, sizeof(visited));

		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				rst = BFS(i, j);
			}
		}
	}
	return 0;
}