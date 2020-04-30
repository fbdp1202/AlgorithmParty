// baekjoon 11660 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1024
int N, M, x1, y1, x2, y2, data[MAX_N+1][MAX_N+1];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			scanf("%d", &data[i][j]);
			data[i][j] += data[i-1][j] + data[i][j-1] - data[i-1][j-1];
		}
	}

	while (M--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", data[x2][y2]-data[x1-1][y2]-data[x2][y1-1]+data[x1-1][y1-1]);
	}
	return 0;
}