// baekjoon 5212 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

char mp[10][11];
bool visited[10][10];
int R, C;

void dfs(int x, int y) {
	visited[x][y]=true;
	int waterNum=0;
	for (int d=0; d<4; d++) {
		int nx=dir[d][0]+x;
		int ny=dir[d][1]+y;
		if (nx < 0 || nx >= R || ny < 0 || ny >= C) waterNum++;
		else if (visited[nx][ny]) continue;
		else if (mp[nx][ny]=='.') waterNum++;
		else dfs(nx, ny);
	}
	if (waterNum>=3) mp[x][y]='.';
}

int main() {
	scanf("%d%d", &R, &C);
	for (int i=0; i<R; i++)
		scanf("%s", mp[i]);

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (visited[i][j]) continue;
			if (mp[i][j]=='.') continue;
			dfs(i, j);
		}
	}

	int sx=100, sy=100;
	int ex=-1, ey=-1;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (mp[i][j]=='X') {
				sx=min(sx, i);
				sy=min(sy, j);
				ex=max(ex, i);
				ey=max(ey, j);
			}
		}
	}

	for (int i=sx; i<=ex; i++) {
		for (int j=sy; j<=ey; j++)
			printf("%c", mp[i][j]);
		printf("\n");
	}

	return 0;
}