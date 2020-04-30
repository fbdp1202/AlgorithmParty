#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=10;
const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

char board[N][N+1];
bool visited[N][N];

void fillDfs(int x, int y, char a) {
	visited[x][y] = true;
	for (int d=0; d<8; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (visited[nx][ny]) continue;
		if (board[nx][ny] == a) continue;
		fillDfs(nx, ny, a);
	}
}

int main() {
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	int comp=0;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (!visited[i][j] && board[i][j] == '1')
				fillDfs(i, j, '0'), comp++;

	if (comp != 1) return !printf("0\n");

	memset(visited, 0, sizeof(visited));
	comp = 0;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (!visited[i][j] && board[i][j] == '0')
				fillDfs(i, j, '1'), comp++;

	if (comp != 1) return !printf("0\n");
	printf("HELLO\n");
	return 0;
}