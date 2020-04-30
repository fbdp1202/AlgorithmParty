// baekjoon 6593 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 31
const int dx[6] = {0, 0, 0, 0, -1, 1};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dz[6] = {-1, 1, 0, 0, 0, 0};

struct Point {
	int x, y, z;
	Point(int a, int b, int c) { x = a; y = b; z = c; };
	Point() {};
};

int L, R, C;

int main() {
	while (1) {
		char board[MAX_N][MAX_N][MAX_N];
		int visited[MAX_N][MAX_N][MAX_N] = {0, };
		scanf("%d%d%d", &L, &R, &C);
		if (!L && !R && !C) break;

		Point sp, ep;
		for (int i=0; i<L; i++) {
			for (int j=0; j<R; j++) {
				scanf(" %s", board[i][j]);
				for (int k=0; k<C; k++) {
					if (board[i][j][k] == 'S') {
						sp = Point(i, j, k);
					}
					if (board[i][j][k] == 'E') {
						ep = Point(i, j, k);
					}
				}
			}
		}
		queue<Point> q;
		q.push(sp);

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			int cx = cur.x;
			int cy = cur.y;
			int cz = cur.z;
			for (int d=0; d<6; d++) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				int nz = cz + dz[d];

				if (0 <= nx && nx < L &&
					0 <= ny && ny < R &&
					0 <= nz && nz < C &&
					!visited[nx][ny][nz] &&
					board[nx][ny][nz] != '#') {
					visited[nx][ny][nz] = visited[cx][cy][cz] + 1;
					q.push(Point(nx, ny, nz));
				}
			}
		}

		if (visited[ep.x][ep.y][ep.z] == 0) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", visited[ep.x][ep.y][ep.z]);
	}
	return 0;
}