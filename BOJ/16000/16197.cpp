// baekjoon 16197 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N = 21;
const int dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

struct Ball{
	int x, y;
	Ball():Ball(0,0){}
	Ball(int x, int y): x(x), y(y){}
};

struct Game{
	Ball b1, b2;
	Game(){}
	Game(int b1x, int b1y, int b2x, int b2y) {
		b1.x = b1x;
		b1.y = b1y;
		b2.x = b2x;
		b2.y = b2y;
	}
};

int N, M;
char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N][MAX_N];
Ball balls[2];

int BFS() {
	Game g = Game(balls[0].x, balls[0].y, balls[1].x, balls[1].y);
	queue<Game> q;
	q.push(g);
	visited[g.b1.x][g.b1.y][g.b2.x][g.b2.y]=true;

	int depth=1;
	while (q.size()) {
		int qSize = q.size();
		while (qSize--) {
			int b1x = q.front().b1.x;
			int b1y = q.front().b1.y;
			int b2x = q.front().b2.x;
			int b2y = q.front().b2.y;
			q.pop();
			for (int d=0; d<4; d++) {
				int nb1x = b1x + dir[d][0];
				int nb1y = b1y + dir[d][1];
				int nb2x = b2x + dir[d][0];
				int nb2y = b2y + dir[d][1];
				int outball1=0, outball2=0;
				if (nb1x < 0 || nb1x >= N || nb1y < 0 || nb1y >= M) outball1=1;
				if (nb2x < 0 || nb2x >= N || nb2y < 0 || nb2y >= M) outball2=1;
				if (outball1 && outball2) continue;
				if (outball1 || outball2) return depth;
				if (board[nb1x][nb1y] == '#') {
					nb1x = b1x;
					nb1y = b1y;
				}
				if (board[nb2x][nb2y] == '#') {
					nb2x = b2x;
					nb2y = b2y;
				}
				if (!visited[nb1x][nb1y][nb2x][nb2y]) {
					visited[nb1x][nb1y][nb2x][nb2y] = true;
					q.push(Game(nb1x, nb1y, nb2x, nb2y));
				}
			}
		}
		depth++;
		if (depth > 10) break;
	}
	return -1;
}

int main() {
	int ballnum=0;
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
		scanf("%s", board[i]);
		for (int j=0; j<M; j++) {
			if (board[i][j] == 'o') {
				balls[ballnum] = Ball(i,j);
				ballnum++;
			}
		}
	}
	printf("%d\n", BFS());

	return 0;
}