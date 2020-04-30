// baekjoon 2573 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX_N = 301;
struct Pos{
	int x, y;
	Pos(){}
	Pos(int x, int y):x(x), y(y){}
};

int N, M, cnt, board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<Pos> ice;

int meltIce(int x, int y, int icetime) {
	int waters = 0;
	for (int d=0; d<4; d++) {
		int nx = x + dir[d][0], ny = y + dir[d][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (visited[nx][ny] == icetime) continue;
		if (!board[nx][ny]) waters++;
	}
	return waters;
}

int DFS(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return 0;
	if (!board[x][y]) return 0;
	if (!visited[x][y]) return 0;
	visited[x][y]=0;
	int rst = 1;
	for (int d=0; d<4; d++){
		rst += DFS(x+dir[d][0], y+dir[d][1]);
	}
	return rst;
}

void PrintBoard() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%d ", board[i][j]);
		}
		puts("");
	}
	puts("");
}

int BFS() {
	queue<Pos> q;
	for (int i=0; i<ice.size(); i++) q.push(ice[i]);

	int icetime = 1;
	while(q.size()) {
		int qSize = q.size();
		while (qSize--) {
			int x = q.front().x, y = q.front().y; q.pop();
			visited[x][y]=icetime;
			int rst = meltIce(x, y, icetime);
			board[x][y] = max(0, board[x][y]-rst);
			if (board[x][y]) q.push(Pos(x,y));
			else cnt--;
		}
		if (q.empty()) return 0;
		if (cnt != DFS(q.front().x, q.front().y)) return icetime;
		icetime++;
	}
	return 0;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			int x; scanf("%d", &x);
			board[i][j] = x;
			if (x) ice.push_back(Pos(i, j)), cnt++;
		}
	}
	printf("%d", BFS());
	return 0;
}