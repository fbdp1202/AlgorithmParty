// baekjoon 1938 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51;
const int dir[2][6][2]={
	{{-1,-1},{1,-1},{-1,0},{1,0},{-1,1},{1,1}},
	{{-1,-1},{0,-1},{1,-1},{-1,1},{0,1},{1,1}}
};

int N;
char board[MAX_N][MAX_N];

bool isOutRange(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

struct Stick{
	int x, y, d;
	Stick():Stick(0,0,0){}
	Stick(int x1, int y1, int dir1):x(x1),y(y1),d(d1){}
	bool isTurn() {
		for (int i=0; i<6; i++) {
			int nx = x + dir[d][i][0];
			int ny = y + dir[d][i][1];
			if (isOutRange(nx, ny)) return false;
			if (board[nx][ny] == '1') return false;
		}
		return true;
	}
};

Stick s, e;

const int stickdir[2][2][2] = {
	{{0,-1},{0,1}},
	{{-1,0},{1,0}}
};

void check(int x, int y) {
	if (board[x][y] != 'B' && board[x][y] != 'E') return;
	for (int d=0; d<2; d++) {
		bool flag = true;
		for (int i=0; i<2; i++) {
			int nx = x + stickdir[d][i][0];
			int ny = y + stickdir[d][i][1];
			if (isOutRange(nx, ny) || board[x][y] != board[nx][ny]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (board[x][y] == 'B') s = Stick(x,y,d);
			else e = Stick(x,y,d);

			board[x][y] = '0';
			for (int i=0; i<2; i++) {
				int nx = x + stickdir[d][i][0];
				int ny = y + stickdir[d][i][1];
				board[nx][ny] = '0';
			}
		}
	}
}

bool visited[2][MAX_N][MAX_N];

int BFS() {
	queue<Stick> q;
	q.push(s);
	visited[s.d][s.x][s.y]=true;

	int depth = 0;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			Stick cur = q.front();
			q.pop();
			if (cur.x == e.x && cur.y == e.y && cur.d == e.d) return depth;
			visited[cur.d][cur.x][cur.y]=true;
			for ()
		}
	}
	return 0;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			check(i,j);

	printf("%d\n", BFS());
	return 0;
}