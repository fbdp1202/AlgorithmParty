// baekjoon 2339 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=21;

int N, board[MAX_N][MAX_N];

ll check(int a1, int b1, int a2, int b2) {
	int star = 0;
	int poison = 0;
	for (int i=a1; i<=a2; i++)
		for (int j=b1; j<=b2; j++) {
			if (board[i][j] == 1) poison++;
			if (board[i][j] == 2) star++;
		}
	if (!star) return -1;
	if (poison == 0 && star > 1) return -1;
	if (poison == 0 && star == 1) return 1;
	return 0;
}

bool cutting(int a1, int b1, int a2, int b2) {
	int poison = 0;
	for (int i=a1; i<=a2; i++)
		for (int j=b1; j<=b2; j++) {
			if (board[i][j] == 1) poison++;
			if (board[i][j] == 2) return false;
		}

	return (poison > 0);
}

ll solve(int a1, int b1, int a2, int b2, int dir) {
	ll ans = check(a1,b1,a2,b2);
	if (ans == -1) return 0;
	if (ans == 0) {
		ll ret = 0;
		if (dir != 0) {
			for (int i=a1+1; i<=a2-1; i++)
				if (cutting(i,b1,i,b2))
					ret += solve(a1, b1, i-1, b2, 0)*solve(i+1, b1, a2, b2, 0);
		} else {
			for (int j=b1+1; j<=b2-1; j++)
				if (cutting(a1,j,a2,j))
					ret += solve(a1, b1, a2, j-1, 1)*solve(a1, j+1, a2, b2, 1);
		}
		return ret;
	}
	return 1;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);

	if (check(0,0,N-1,N-1) == 1) return !printf("1\n");
	ll ret = solve(0,0,N-1,N-1,0) + solve(0,0,N-1,N-1,1);
	if (ret == 0) printf("-1\n");
	else printf("%lld\n", ret);
	return 0;
}