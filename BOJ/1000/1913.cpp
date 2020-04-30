// baekjoon 1913 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, d, e, ex, ey, matrix[999][999];

int main() {
	scanf("%d%d", &N, &e);
	int cx = N/2, cy=N/2;
	int cnt = 0, length=1, cur_step=0;
	for (int i=1; i<=N*N; i++) {
		matrix[cx][cy] = i;
		if (i == e) ex = cx+1, ey = cy+1;
		cx = cx + dx[d];
		cy = cy + dy[d];
		cur_step++;
		if (cur_step == length) {
			if (cnt) cnt=0, length++, cur_step=0;
			else cnt=1, cur_step=0;
			d=(d+1)%4;
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			printf("%d ", matrix[i][j]);
		}
		puts("");
	}
	printf("%d %d\n", ex, ey);
	return 0;
}