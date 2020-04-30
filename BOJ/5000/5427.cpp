// baekjoon 5427 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
#define MAX_N 1001
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int INF_MAX = 987654321;
typedef pair<int, int> P;

int visited[MAX_N][MAX_N];
char board[MAX_N][MAX_N];

int main() {
	int T, W, H;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &W, &H);
		memset(visited, 0, sizeof(visited));
		int sx = 0, sy = 0;

		vector<P> fire;
		bool flag = false;

		for (int i=0; i<H; i++)
			scanf("%s", board[i]);

		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				if (board[i][j] == '@') {
					sx = i, sy = j;
				}
				if (board[i][j] == '*') {
					fire.push_back(P(i, j));
				}
			}
		}

		queue<P> qPerson;
		queue<P> qFire;

		for (int i=0; i<fire.size(); i++) {
			qFire.push(P(fire[i].first, fire[i].second));
		}
		qPerson.push(P(sx, sy));

		visited[sx][sy] = 1;

		int depth = 0;
		while (!qPerson.empty()) {
			depth++;
			int qPersonSize=qPerson.size();
			for (int i=0; i<qPersonSize; i++) {
				int cx = qPerson.front().first;
				int cy = qPerson.front().second;

				qPerson.pop();

				if (board[cx][cy] == '*') continue;

				for (int d=0; d<4; d++) {
					int nx = cx + dx[d];
					int ny = cy + dy[d];

					if (0<=nx && nx<H &&
						0<=ny && ny<W) {
						if (!visited[nx][ny] && board[nx][ny] == '.') {
							visited[nx][ny]=1;
							qPerson.push(P(nx, ny));
						}
					}
					else {
						printf("%d\n", depth);
						flag=true;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;

			int qFireSize=qFire.size();

			for (int i=0; i<qFireSize; i++) {
				int cx = qFire.front().first;
				int cy = qFire.front().second;
				qFire.pop();

				for (int d=0; d<4; d++) {
					int nx = cx + dx[d];
					int ny = cy + dy[d];

					if (0<=nx && nx<H &&
						0<=ny && ny<W &&
						board[nx][ny] == '.') {
						qFire.push(P(nx, ny));
						board[nx][ny] = '*';
					}
				}
			}
		}

		if(!flag) printf("IMPOSSIBLE\n");
	}
	return 0;
}