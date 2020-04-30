// baekjoon 3085 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51;
const int dir[2][2]={{0,1},{1,0}};

int N;
char board[MAX_N][MAX_N];

int test() {
	int ret = 0;
	for (int i=0; i<N; i++) {
		int cnt = 0;
		char pv = '\0';
		for (int j=0; j<N; j++) {
			if (pv == board[i][j]) {
				cnt++;
			} else {
				cnt = 1;
				pv = board[i][j];
			}
			ret = max(ret, cnt);
		}
	}

	for (int j=0; j<N; j++) {
		int cnt = 0;
		char pv = '\0';
		for (int i=0; i<N; i++) {
			if (pv == board[i][j]) {
				cnt++;
			} else {
				cnt = 1;
				pv = board[i][j];
			}
			ret = max(ret, cnt);
		}
		ret = max(ret, cnt);
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	int ret = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			for (int d=0; d<2; d++) {
				int nx = i + dir[d][0];
				int ny = j + dir[d][1];
				if (nx >= N || ny >= N) continue;
				if (board[i][j] == board[nx][ny]) continue;
				swap(board[i][j], board[nx][ny]);
				ret = max(ret, test());
				swap(board[i][j], board[nx][ny]);
			}
		}
	}
	printf("%d\n", ret);

	return 0;
}