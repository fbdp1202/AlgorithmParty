// baekjoon 2458 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=501;

int N, M, u, v;
bool indeg[MAX_N][MAX_N], outdeg[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		indeg[i][i]=outdeg[i][i]=true;

	for (int i=0; i<M; i++) {
		scanf("%d%d", &u, &v);
		indeg[u-1][v-1]=true;
		outdeg[v-1][u-1]=true;
	}

	for (int k=0; k<N; k++) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				indeg[i][j] |= indeg[i][k] && indeg[k][j];
				outdeg[i][j] |= outdeg[i][k] && outdeg[k][j];
			}
		}
	}

	int cnt=0;
	for (int i=0; i<N; i++) {
		bool flag=false;
		for (int j=0; j<N; j++)
			if (!indeg[i][j] && !outdeg[i][j])
				flag=true;
		if (!flag)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}