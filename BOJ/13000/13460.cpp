// baekjoon 13460 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct Point{
	int x, y;
	Point():Point(0,0){}
	Point(int x, int y):x(x), y(y){}
	Point operator=(Point a) {
		x = a.x; y = a.y;
	}
};

struct Ball{
	Point red, blue;
	Ball():{}
	Ball(Point red, Point blue) {
		red = red; blue = blue;
	}
}

int N, M, srx, sry, sbx, sby;
bool visited[10][10][10][10];
char board[11][11];

int BFS() {
	queue<Ball> q;
	q.push(Ball(Point(srx, sry), Point(sbx, sby)));
	visited[srx][sry][sbx][sby]=true;

	int depth = 1;
	while (q.size()) {
		int qSize = q.size();
		while (qSize--) {
			int rx = q.front().red.x;
			int ry = q.front().red.y;
			int bx = q.front().blue.x;
			int by = q.front().blue.y;
			q.pop();
			for (int d=0; d<4; d++) {
				int nrx = rx, nry = ry;
				int nbx = bx, nby = by;
				while (board[nrx + dx[d]][nry + dy[d]] != '#' ||
					   board[nbx + dx[d]][nby + dy[d]] != '#') {
					if ()
				}
			}
		}
		depth++;
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++){
		scanf("%s", board[i]);
		for (int j=0; j<M; j++) {
			if (board[i][j] == 'R') {
				srx = i; sry = j;
			}
			if (board[i][j] == 'B') {
				sbx = i; sby = j;
			}
		}
	}

	printf("%d\n", BFS());
	return 0;
}
