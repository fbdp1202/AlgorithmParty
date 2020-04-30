// baekjoon 2665 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <algorithm>
using namespace std;
const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int MAX_N=51;
typedef pair<int, pair<int,int> > PP;

int N;
char board[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
vector<PP> adj[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	// genterate connections
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			for (int d=0; d<4; d++) {
				int nx = i + dir[d][0];
				int ny = j + dir[d][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				adj[i][j].push_back({ !(board[nx][ny]-'0'), {nx, ny}});
				adj[nx][ny].push_back({ !(board[i][j]-'0'), {i, j}});
			}
		}
	}

	priority_queue<PP, vector<PP>, greater<PP> > PQ;
	for (int i=0; i<N; i++)
		fill(dist[i], dist[i]+MAX_N, 100);

	dist[0][0] = 0;
	PQ.push({0, {0,0}});
	while (!PQ.empty()) {
		int cur_x, cur_y;
		do {
			cur_x = PQ.top().second.first;
			cur_y = PQ.top().second.second;
			PQ.pop();
		} while (!PQ.empty() && visited[cur_x][cur_y]);
		if (visited[cur_x][cur_y]) break;
		visited[cur_x][cur_y] = true;

		for (auto& p: adj[cur_x][cur_y]) {
			int nx = p.second.first, ny = p.second.second, d = p.first;
			if (dist[nx][ny] > dist[cur_x][cur_y] + d) {
				dist[nx][ny] = dist[cur_x][cur_y] + d;
				PQ.push({dist[nx][ny], {nx,ny}});
			}
		}
	}
	printf("%d\n", dist[N-1][N-1]);
	return 0;
}