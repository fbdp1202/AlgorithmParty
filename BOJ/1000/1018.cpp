// baekjoon 1018 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51;

int N, M;
char board[MAX_N][MAX_N];
const char check[3]="BW";

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	int ret = 1e9;
	for (int si=0; si<N-7; si++) {
		for (int sj=0; sj<M-7; sj++) {
			int cnt = 0;
			for (int i=0; i<8; i++) {
				for (int j=0; j<8; j++) {
					int x = si+i, y = sj+j;
					if (board[x][y] == check[(x+y)%2]) cnt++;
				}
			}
			ret = min(ret, min(cnt, 64-cnt));
		}
	}
	printf("%d\n", ret);

	return 0;
}