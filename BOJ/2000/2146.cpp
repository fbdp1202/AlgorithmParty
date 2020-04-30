// baekjoon 2146 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N = 101;
const int INF=1e9;
const int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
typedef pair<pair<int, int>, int> P;
int N, cnt;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
queue<P> q;

void dfs(int x, int y, int idx) {
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (visited[x][y]) return;
	if (!board[x][y]) return;
	visited[x][y]=true;
	q.push({{x, y}, idx});
	for (int d=0; d<4; d++)
		dfs(x+dir[d][0], y+dir[d][1], idx);
}

int bfs() {
	int depth=0;
	int ret=INF;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int cur_x = q.front().first.first;
			int cur_y = q.front().first.second;
			int cur_idx = q.front().second;
			q.pop();
			for (int d=0; d<4; d++) {
				int nx = cur_x + dir[d][0];
				int ny = cur_y + dir[d][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (board[nx][ny] == 1) continue;
				if (board[nx][ny] == cur_idx) continue;
				if (board[nx][ny] == 0) {
					board[nx][ny] = cur_idx;
					q.push({{nx, ny}, cur_idx});
				}
				else {
					ret = min(ret, depth*2 + (board[nx][ny] < cur_idx));
				}
			}
		}
		if (ret!=INF) return ret;
		depth++;
	}
	return -1;
}

int main(){
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);

	cnt=2;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (!visited[i][j] && board[i][j])
				dfs(i, j, cnt++);

	printf("%d\n", bfs());
	return 0;
}