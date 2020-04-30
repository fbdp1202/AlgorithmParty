// baekjoon 16057 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001
int N, M, Q, r1, c1, r2, c2, matrix[MAX_N][MAX_N];

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=M; j++) {
			scanf("%d", &matrix[i][j]);
			matrix[i][j] += matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
		}
	}

	while (Q--) {
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		printf("%d\n", (matrix[r2][c2]-matrix[r2][c1-1]-matrix[r1-1][c2]+matrix[r1-1][c1-1])/((r2-r1+1)*(c2-c1+1)));
	}
	return 0;
}