// baekjoon 2206 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 1001
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
typedef pair<pair<int,int>, int> P;

int N, M, visited[MAX_N][MAX_N];
char board[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf(" %s", board[i]);

	queue<P> q;
	visited[0][0] = 1;

	int depth = 1;
	bool flag = false;
	q.push(P({0,0},0));
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int cx = q.front().first.first;
			int cy = q.front().first.second;
			if (cx == N-1 && cy == M-1) {
				printf("%d\n", depth);
				flag = true;
				break;
			}
			int block = q.front().second;
			q.pop();

			for (int d=0; d<4; d++) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (block) {
					if (visited[nx][ny] != 0) continue;
					if (board[nx][ny] == '0') {
						visited[nx][ny] = 2;
						q.push(P({nx, ny}, 1));
					}
				} else{
					if (visited[nx][ny] == 1) continue;
					if (board[nx][ny] == '1') {
						visited[nx][ny] = 2;
						q.push(P({nx, ny}, 1));
					}
					if (board[nx][ny] == '0') {
						visited[nx][ny] = 1;
						q.push(P({nx, ny}, 0));
					}
				}

			}
		}
		if (flag) break;
		depth++;
	}
	if (!flag) printf("-1\n");
	return 0;
}