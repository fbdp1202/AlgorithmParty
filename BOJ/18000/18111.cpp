#include <bits/stdc++.h>
using namespace std;

const int MAX_N=501;
const int MAX_INF=2e9;

int N, M, B, board[MAX_N][MAX_N];

int main() {
	scanf("%d%d%d", &N, &M, &B);

	int min_h=MAX_INF;
	int max_h=0;

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf("%d", &board[i][j]);
			min_h = min(min_h, board[i][j]);
			max_h = max(max_h, board[i][j]);
		}
	}

	int ret = MAX_INF;
	int ret_h = 0;
	for (int h=min_h; h<=max_h; h++) {
		int sum_remove=0, sum_build=0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				sum_remove += max(0, board[i][j] - h);
				sum_build += max(0, h - board[i][j]);
			}
		}
		if (sum_build <= sum_remove + B) {
			int ans = sum_remove*2 + sum_build;
			if (ans <= ret) ret=ans, ret_h=h;
		}
	}
	printf("%d %d\n", ret, ret_h);
	return 0;
}