// baekjoon 2589 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
typedef pair<int, int> P;

char map[51][51];
int N, M, result, visited[50][50], dist[50][50];

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++){
		scanf("%s", map[i]);
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if(map[i][j] == 'L') {
				memset(visited, 0, sizeof(visited));
				memset(dist, 0, sizeof(dist));
				queue<P> q;
				q.push(P(i, j));
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int d=0; d<4; d++) {
						int nx = x + dx[d];
						int ny = y + dy[d];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (visited[nx][ny] || map[nx][ny] == 'W') continue;
						visited[nx][ny]=true;
						dist[nx][ny]= dist[x][y] + 1;
						result = max(result, dist[nx][ny]);
						q.push(P(nx, ny));
					}
				}
			}
		}
	}

	printf("%d\n", result);
	return 0;
}