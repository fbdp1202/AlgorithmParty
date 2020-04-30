// baekjoon 2642 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

struct Rect{
	int value;
	int idx;
	Rect *up, *down, *right, *left;
	Rect():idx(0), value(0){}
};

Rect rect[6];
int board[6][6], sx, sy;
bool visited[6][6];

void initRect() {
	rect[0].value = 0;
	rect[0].idx   = 0;
	rect[0].up    = &rect[3];
	rect[0].down  = &rect[4];
	rect[0].left  = &rect[1];
	rect[0].right = &rect[2];

	rect[1].value = 0;
	rect[1].idx   = 1;
	rect[1].up    = &rect[3];
	rect[1].down  = &rect[4];
	rect[1].left  = &rect[5];
	rect[1].right = &rect[0];

	rect[2].value = 0;
	rect[2].idx   = 2;
	rect[2].up    = &rect[3];
	rect[2].down  = &rect[4];
	rect[2].left  = &rect[0];
	rect[2].right = &rect[5];

	rect[3].value = 0;
	rect[3].idx   = 3;
	rect[3].up    = &rect[5];
	rect[3].down  = &rect[0];
	rect[3].left  = &rect[1];
	rect[3].right = &rect[2];

	rect[4].value = 0;
	rect[4].idx   = 4;
	rect[4].up    = &rect[0];
	rect[4].down  = &rect[5];
	rect[4].left  = &rect[1];
	rect[4].right = &rect[2];

	rect[5].value = 0;
	rect[5].idx   = 5;
	rect[5].up    = &rect[4];
	rect[5].down  = &rect[3];
	rect[5].left  = &rect[1];
	rect[5].right = &rect[2];
}

const int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
// { up, down, left, right }
bool dfs(int x, int y, Rect *cur, int pv) {
	int nx, ny;
	bool ret=true;

	if (cur->idx == 5 && (pv == 1 || pv == 2)) {
		swap(rect[5].left, rect[5].right);
		swap(rect[5].up, rect[5].down);
	}
	visited[x][y] = true;

	if (cur->value) return false;

	cur->value = board[x][y];
	// up
	nx = x + dir[0][0];
	ny = y + dir[0][1];
	if (0 <= nx && nx < 6 && 0 <= ny && ny < 6) {
		if (board[nx][ny] && !visited[nx][ny]) {
			 ret &= dfs(nx, ny, cur->up, cur->idx);
		}
	}

	// down
	nx = x + dir[1][0];
	ny = y + dir[1][1];
	if (0 <= nx && nx < 6 && 0 <= ny && ny < 6) {
		if (board[nx][ny] && !visited[nx][ny]) {
			 ret &= dfs(nx, ny, cur->down, cur->idx);
		}
	}

	// left
	nx = x + dir[2][0];
	ny = y + dir[2][1];
	if (0 <= nx && nx < 6 && 0 <= ny && ny < 6) {
		if (board[nx][ny] && !visited[nx][ny]) {
			 ret &= dfs(nx, ny, cur->left, cur->idx);
		}
	}

	// right
	nx = x + dir[3][0];
	ny = y + dir[3][1];
	if (0 <= nx && nx < 6 && 0 <= ny && ny < 6) {
		if (board[nx][ny] && !visited[nx][ny]) {
			 ret &= dfs(nx, ny, cur->right, cur->idx);
		}
	}
	return ret;
}

int main() {
	for (int i=0; i<6; i++) {
		for (int j=0; j<6; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int i=0; i<6; i++) {
		for (int j=0; j<6; j++) {
			if (board[i][j] != 0) {
				initRect();
				bool ans = dfs(i, j, &rect[0], -1);
				int idx = 5;
				if (ans) {
					for (int i=0; i<6; i++) {
						if (rect[i].value == 1)
							idx=i;
						}
					return !printf("%d\n", rect[idx].right->right->value);
				}
			}
		}
	}
	printf("0\n");
	return 0;
}