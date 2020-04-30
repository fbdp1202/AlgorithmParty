// baekjoon 15684 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=11;
const int MAX_H=31;
const int MAX_M=301;
const int MAX_INF=1e9;

int N, M, H;
int line[MAX_H][MAX_N]; // if line[i][j] = 1, (i,j)<->(i,j+1) connect
int tmp[MAX_H][MAX_N];
int ans;

bool simulation() {
	for (int i=1; i<=N; i++)
		tmp[1][i]=i;

	for (int i=1; i<=H; i++) {
		for (int j=1; j<=N; j++) {
			if (line[i][j]) {
				tmp[i+1][j] = tmp[i][j+1];
			} else if (line[i][j-1]) {
				tmp[i+1][j] = tmp[i][j-1];
			} else {
				tmp[i+1][j] = tmp[i][j];
			}
		}
	}

	for (int i=1; i<=N; i++)
		if (tmp[H+1][i] != i)
			return false;
	return true;
}

int dfs(int h, int here) {
	if (here > 3) return MAX_INF;
	if (here >= ans) return here;

	if (simulation()) {
		ans = min(ans, here);
		return here;
	}

	int ret = MAX_INF;
	for (int i=h; i<=H; i++) {
		for (int j=1; j<=N-1; j++) {
			if (line[i][j-1] + line[i][j] + line[i][j+1]) continue; // 라인 추가 불가능
			line[i][j] = 1;
			ret = min(ret, dfs(i, here + 1));
			line[i][j] = 0;
			if (ans <= here + 1) return ret;
		}
	}
	return ret;
}

int main() {
	scanf("%d%d%d", &N, &M, &H);
	for (int i=0; i<M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		line[a][b] = 1;
	}

	ans = MAX_INF;
	dfs(1, 0);
	printf("%d\n", ans == MAX_INF ? -1 : ans);
	return 0;
}