// baekjoon 10711 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> P;
const int MAX_N=1001;
const int dir[8][2] = {{-1,-1}, {-1,0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int W, H;
char board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int BFS() {
	queue<P> q;
	for (int i=0; i<H; i++)
		for (int j=0; j<W; j++)
			if (board[i][j] != '.' || board[i][j] != '9')
				q.push(P(i,j));

	int depth = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i=0; i<qSize; i++) {
			int cur_x = q.front().first, cur_y = q.front().second;
			q.pop();
			int cnt = 0;
			for (int d=0; d<8; d++) {
				int nx = cur_x + dir[d][0], ny = cur_y + dir[d][1];
				if (board[nx][ny] != '.') continue;
				if (visited[nx][ny] == depth+1) continue;
				cnt++;
			}
			if ((board[cur_x][cur_y]-'0') <= cnt) {
				board[cur_x][cur_y]='.';
				visited[cur_x][cur_y]=depth+1;
			} else {
				q.push(P(cur_x, cur_y));
			}
		}
		if (qSize == q.size()) return depth;
		depth++;
	}
	return depth;
}

int main() {
	scanf("%d%d", &H, &W);
	for (int i=0; i<H; i++)
		scanf("%s", board[i]);
	printf("%d\n", BFS());
	return 0;
}