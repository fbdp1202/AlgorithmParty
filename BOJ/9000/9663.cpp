// baekjoon 9663 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 16
#define DEBUG_MODE
int N;
int row[MAX_N], col[MAX_N], d1[MAX_N*2], d2[MAX_N*2];

void removeBoard(int x, int y, int num) {
	row[x]=0;
	col[y]=0;
	d1[N+(x-y)]=0;
	d2[x+y]=0;
}

void fillBoard(int x, int y, int num) {
	row[x]=num;
	col[y]=num;
	d1[N+(x-y)]=num;
	d2[x+y]=num;
}

bool checkBoard(int x, int y) {
	return row[x] || col[y] || d1[N+(x-y)] || d2[x+y];
}

int backTracking(int idx) {
	if (idx == N) {
		return 1;
	}

	int rst = 0;
	for (int i=0; i<N; i++) {
		if (checkBoard(idx, i)) continue;
		fillBoard(idx, i, idx+1);
		rst += backTracking(idx+1);
		removeBoard(idx, i, idx+1);
	}
	return rst;
}

int main() {
	scanf("%d", &N);
	printf("%d\n", backTracking(0));
	return 0;
}