// baekjoon 2468 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 100

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int input_buf[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int N, h, lo, hi, mid, rst, num;

static void SetInputBuffer( void ) {
	lo=987654321; hi=0;
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%d", &input_buf[i][j]);
			lo = min(lo, input_buf[i][j]);
			hi = max(hi, input_buf[i][j]);
		}
	}
}

static void dfs(int x, int y) {
	if (x >= N || y >= N || x < 0 || y < 0) return;

	if (visited[y][x] || input_buf[y][x] <= h) return;

	visited[y][x]=1;

	for (int d=0; d<4; d++) {
		int nx = dx[d] + x;
		int ny = dy[d] + y;
		dfs(nx, ny);
	}
}

int main() {
	SetInputBuffer();

	rst = 1;
	for (h = lo; h < hi; h++) {
		memset(visited, 0, sizeof(visited));
		num=0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (!visited[i][j] && input_buf[i][j] > h) {
					dfs(j, i);
					num++;
				}
			}
		}
		rst = max(rst, num);
	}
	printf("%d", rst);
	return 0;
}