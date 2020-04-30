// baekjoon 2617 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;

int N, M;
bool uboard[MAX_N][MAX_N];
bool lboard[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--,v--;
		uboard[u][v]=true;
		lboard[v][u]=true;
	}

	for (int k=0; k<N; k++) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (i == j || j == k) continue;
				uboard[i][j] |= uboard[i][k] && uboard[k][j];
				lboard[i][j] |= lboard[i][k] && lboard[k][j];
			}
		}
	}

	int ret = 0;
	for (int i=0; i<N; i++) {
		int up = 0, down = 0;
		for (int j=0; j<N; j++) {
			up += uboard[i][j];
			down += lboard[i][j];
		}
		if (up > N/2 || down > N/2) ret++;
	}
	printf("%d\n", ret);
	return 0;
}