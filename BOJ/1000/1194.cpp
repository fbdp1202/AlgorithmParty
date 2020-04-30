// baekjoon 1194 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAX_N 50
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
typedef pair<pair<int, int>, int> P;

int N, M, sx, sy, visited[MAX_N][MAX_N][1<<7];

char board[MAX_N][MAX_N];

void BinaryPrint(int num) {
	for (int i=0; i<18; i++)
		printf("%d", (num>>i) & 1);
	puts("");
}

int bfs() {
	queue<P> q;
	q.push(P({sx, sy}, 0));
	visited[sx][sy][0]=1;
	int depth = 0;
	while (q.size()){
		int qSize = q.size();
		while (qSize--) {
			int cx = q.front().first.first;
			int cy = q.front().first.second;
			int cflag = q.front().second;
			q.pop();
			if (board[cx][cy] == '1') {
				return depth;
			}
			for (int d=0; d<4; d++) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				int nflag = cflag;
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (board[nx][ny] == '#') continue;
				if ('a' <= board[nx][ny] && board[nx][ny] <= 'f') {
					nflag |= 1<<(board[nx][ny]-'a');
				}
				if (visited[nx][ny][nflag]) continue;
				if ('A' <= board[nx][ny] && board[nx][ny] <= 'F') {
					if ( (nflag>>(board[nx][ny]-'A')) & 1 ){
						visited[nx][ny][nflag]=1;
						q.push(P({nx, ny}, nflag));
					}
				}
				else {
					visited[nx][ny][nflag]=1;
					q.push(P({nx, ny}, nflag));
				}
			}
		}
		depth++;
	}

	return -1;
}

int main() {

	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++){
		scanf("%s", board[i]);
		for (int j=0; j<M; j++){
			if (board[i][j] == '0'){
				sx = i; sy = j;
			}
		}
	}
	printf("%d\n", bfs());
	return 0;
}