// baekjoon 2178 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int MAX_N=128;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, M;
char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

P decode(int code){
	return P(code>>7, code&127);
}

int encode(int x, int y) {
	return (x<<7) + y;
}

int bfs() {
	queue<int> q;
	q.push(encode(0,0));
	visited[0][0] = true;
	int depth = 1;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			P curr = decode(q.front());
			q.pop();
			int x = curr.first;
			int y = curr.second;
			if (x == N-1 && y == M-1) return depth;
			for (int d=0; d<4; d++) {
				int nx = x + dir[d][0];
				int ny = y + dir[d][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (visited[nx][ny]) continue;
				if (board[nx][ny] == '0') continue;
				visited[nx][ny] = true;
				q.push(encode(nx, ny));
			}
		}
		depth++;
	}
	return -1;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);
	printf("%d\n", bfs());
	return 0;
}