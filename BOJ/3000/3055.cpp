// baekjoon 3055 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAX_N 51
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
typedef pair<int, int> P;

int visited[MAX_N][MAX_N];
char board[MAX_N][MAX_N];

int main() {
	int W, H;
	scanf("%d %d", &H, &W);
	int sx = 0, sy = 0, ex = 0, ey = 0;

	vector<P> water;
	bool flag = false;

	for (int i=0; i<H; i++)
		scanf("%s", board[i]);

	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			if (board[i][j] == 'S') {
				sx = i, sy = j;
			}
			if (board[i][j] == '*') {
				water.push_back(P(i, j));
			}
			if (board[i][j] == 'D') {
				ex = i, ey = j;
			}
		}
	}

	queue<P> qAnimal;
	queue<P> qwater;

	for (int i=0; i<water.size(); i++) {
		qwater.push(P(water[i].first, water[i].second));
	}
	qAnimal.push(P(sx, sy));

	visited[sx][sy] = 1;

	int depth = 0;
	while (!qAnimal.empty()) {
		depth++;
		int qwaterSize=qwater.size();
		for (int i=0; i<qwaterSize; i++) {
			int cx = qwater.front().first;
			int cy = qwater.front().second;
			qwater.pop();

			for (int d=0; d<4; d++) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];

				if (0<=nx && nx<H &&
					0<=ny && ny<W &&
					(board[nx][ny] == '.' ||
					 board[nx][ny] == 'S')) {
					qwater.push(P(nx, ny));
					board[nx][ny] = '*';
				}
			}
		}

		int qAnimalSize=qAnimal.size();
		for (int i=0; i<qAnimalSize; i++) {
			int cx = qAnimal.front().first;
			int cy = qAnimal.front().second;

			qAnimal.pop();

			for (int d=0; d<4; d++) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];

				if (0<=nx && nx<H &&
					0<=ny && ny<W) {
					if (nx == ex && ny == ey) {
						printf("%d\n", depth);
						flag=true;
						break;
					}
					if (!visited[nx][ny] && board[nx][ny] == '.') {
						visited[nx][ny]=1;
						qAnimal.push(P(nx, ny));
					}
				}
			}
			if (flag)
				break;
		}
		if (flag)
			break;
	}

	if(!flag) printf("KAKTUS\n");

	return 0;
}