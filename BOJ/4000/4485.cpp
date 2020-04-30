// baekjoon 4485 yechan
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX_N = 125;
const int INF = 1e9;
const int dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
typedef pair<int, int> P;

int N, board[MAX_N][MAX_N], cnt;
vector<vector<int> > dist;
vector<vector<bool> > visited;
vector<vector<P> > adj;

inline void encode(int x, int y, int &code) {
	code = (x<<7) | y;
}

inline void decode(int code, int &x, int &y) {
	x = code>>7;
	y = code & 0b1111111;
}

int Dijkstra(int sx, int sy, int dx, int dy) {
	priority_queue<P, vector<P>, greater<P> > PQ;
	dist[sx][sy]=board[sx][sy];
	int code;
	encode(sx, sy, code);
	PQ.push(P(0,code));

	while (!PQ.empty()) {
		int ccode;
		int cx, cy;
		do {
			ccode = PQ.top().second;
			decode(ccode, cx, cy);
			PQ.pop();
		} while (!PQ.empty() && visited[cx][cy]);
		if (visited[cx][cy]) break;
		visited[cx][cy]=true;
		for (int d=0; d<4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			int ncode;
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (dist[nx][ny] > dist[cx][cy] + board[nx][ny]) {
				dist[nx][ny] = dist[cx][cy] + board[nx][ny];
				encode(nx, ny, ncode);
				PQ.push(P(dist[nx][ny], ncode));
			}
		}
	}

	return (dist[dx][dy] == INF) ? -1 : dist[dx][dy];
}

int main() {
	while (1) {
		cnt++;
		scanf("%d", &N);
		if (!N) break;
		visited = vector<vector<bool> >(N, vector<bool>(N, false));
		adj = vector<vector<P> >(N);
		dist = vector<vector<int> >(N, vector<int>(N, INF));
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; j++)
				scanf("%d", &board[i][j]);
		printf("Problem %d: %d\n", cnt, Dijkstra(0, 0, N-1, N-1));
	}
	return 0;
}