// baekjoon 10159 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N=101;
const int MAX_INF=1e9;
int N, M, dist_x[MAX_N][MAX_N], dist_y[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (i == j) dist_x[i][j] = dist_y[i][j] = 0;
			else dist_x[i][j] = dist_y[i][j] = MAX_INF;
		}
	}
 
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		dist_x[u-1][v-1] = 1;
		dist_y[v-1][u-1] = 1;
	}

	for (int k=0; k<N; k++) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (dist_x[i][j] > dist_x[i][k] + dist_x[k][j]) {
					dist_x[i][j] = dist_x[i][k] + dist_x[k][j];
				}
				if (dist_y[i][j] > dist_y[i][k] + dist_y[k][j]) {
					dist_y[i][j] = dist_y[i][k] + dist_y[k][j];
				}
			}
		}
	}

	for (int i=0; i<N; i++) {
		int ret = 0;
		for (int j=0; j<N; j++) {
			if (dist_x[i][j]==MAX_INF && dist_y[i][j]==MAX_INF) ret++;
		}
		printf("%d\n", ret);
	}
	return 0;
}