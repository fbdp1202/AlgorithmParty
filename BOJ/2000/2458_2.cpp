// baekjoon 2458 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=500;
int N, M, u, v;
bool indeg[MAX_N][MAX_N], outdeg[MAX_N][MAX_N];
bool invisit[MAX_N][MAX_N], outvisit[MAX_N][MAX_N];

void indfs(int here) {
	for (int i=0; i<N; i++) {
		if (!invisit[here][i]) {
			invisit[here][i]=true;
			if (indeg[here][i]) {
				indfs(i);
				for (int j=0; j<N; j++) indeg[here][j] |= indeg[i][j];
			}
		}
	}
}

void outdfs(int here) {
	for (int i=0; i<N; i++) {
		if (!outvisit[here][i]) {
			outvisit[here][i]=true;
			if (outdeg[here][i]) {
				outdfs(i);
				for (int j=0; j<N; j++) outdeg[here][j] |= outdeg[i][j];
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) indeg[i][i]=outdeg[i][i]=true;
	for (int i=0; i<M; i++) {
		scanf("%d%d", &u, &v);
		indeg[u-1][v-1]=true;
		outdeg[v-1][u-1]=true;
	}

	for (int i=0; i<N; i++) {
		indfs(i);
		outdfs(i);
	}

	int ret=0;
	for (int i=0; i<N; i++) {
		int cnt=0;
		for (int j=0; j<N; j++)
			cnt += (indeg[i][j] || outdeg[i][j]);
		if (cnt == N) ret++;
	}
	printf("%d\n", ret);
	return 0;
}