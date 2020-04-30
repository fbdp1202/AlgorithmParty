// baekjoon 16236 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int MAX_N = 20;
const int INF = 1e9;
const int dir[4][2] = {{0,-1},{0,1}, {-1,0}, {1,0}};
int N, sx, sy, fsize=2;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int BFS() {
	queue<P> q;
	q.push(P(sx, sy));
	memset(visited, 0, sizeof(visited));
	visited[sx][sy]=true;
	int depth = 0;
	int fish_x = INF, fish_y = INF;
	bool flag = false;
	while (!q.empty()) {
		int qSzie = q.size();
		while (qSzie--) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			if (board[cx][cy] && board[cx][cy] != 9 && board[cx][cy] < fsize) {
				flag = true;
				if (cx < fish_x) {
					fish_x = cx;
					fish_y = cy;
				}
				else if (cx == fish_x && cy < fish_y) {
					fish_y = cy;
				}
			}
			for (int d=0; d<4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (visited[nx][ny]) continue;
				if (board[nx][ny] > fsize) continue;
				visited[nx][ny]=true;
				q.push(P(nx, ny));
			}
		}
		if (flag) {
			board[sx][sy]=0;
			board[fish_x][fish_y]=9;
			sx = fish_x, sy = fish_y;
			return depth;
		}
		depth++;
	}
	return -1;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 9) {
				sx = i, sy = j;
			}
		}
	}

	int fish_time = 0;
	int cnt=0;
	while (1) {
		int ret = BFS();
		if (ret == -1) {
			printf("%d\n", fish_time);
			break;
		}
		else {
			cnt++;
			if (cnt == fsize) {
				fsize++;
				cnt=0;
			}
			fish_time += ret;
		}
	}

	return 0;
}
