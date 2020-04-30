// baekjoon 10026 yechan
#include <cstdio>
#include <algorithm>
#include <queue>

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

char color[101][101];
int N, origin_num, change_num;
bool visited[101][101];

bool CheckCondition(int x, int y, int flag, char c) {
	if (x < 0 || x >= N || y <0 || y >= N) return false;
	if (visited[x][y]) return false;

	if (flag) {
		switch(c) {
			case 'R' :
			case 'G' : 
				if (color[x][y] == 'B') return false;
				break;
			case 'B' :
				if (color[x][y] != 'B') return false;
				break;
		}
	} else {
		switch(c) {
			case 'R' : 
				if (color[x][y] != 'R') return false; 
				break;
			case 'G' :
				if (color[x][y] != 'G') return false;
				break;
			case 'B' :
				if (color[x][y] != 'B') return false;
				break;
		}
	}
	return true;
}

void DFS(int x, int y, int flag, char c) {
	for (int d=0; d<4; d++) {
		int nx = dx[d] + x;
		int ny = dy[d] + y;
		if(CheckCondition(nx, ny, flag, c)) {
			visited[nx][ny] =true;
			DFS(nx, ny, flag, c);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", color[i]);

	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (!visited[i][j])
				origin_num++, visited[i][j]=true, DFS(i, j, 0, color[i][j]);

	for (int i=0; i<N; i++) 
		for (int j=0; j<N; j++)
			visited[i][j]=false;

	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (!visited[i][j])
				change_num++, visited[i][j]=true, DFS(i, j, 1, color[i][j]);

	printf("%d %d\n", origin_num, change_num);
}