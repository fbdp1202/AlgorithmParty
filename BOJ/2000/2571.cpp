// baekjoon 2571 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100;

int N;
bool board[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {
	scanf("%d", &N);
	for (int t=0; t<N; t++) {
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i=x; i<x+10; i++)
			for (int j=y; j<y+10; j++)
				board[i][j]=true;
	}

	for (int i=1; i<100; i++)
		for (int j=1; j<100; j++)
			if (board[i][j]) dp[i][j] = dp[i-1][j] + 1;

	stack<int> s;
	int ans = 0;
	for (int i=1; i<100; i++) {
		for (int j=1; j<100; j++) {
			int left = j;
			while (!s.empty() && dp[i][s.top()] > dp[i][j]) {
				int height = dp[i][s.top()];
				s.pop();
				int width = j;
				if (!s.empty()) {
					width = (j - s.top() - 1);
				}
				ans = max(ans, width*height);
			}
			s.push(j);
		}
		while (!s.empty()) {
			int height = dp[i][s.top()];
			s.pop();
			int width = MAX_N;
			if (!s.empty()) {
				width = MAX_N-s.top()-1;
			}
			ans = max(ans, width*height);
		}
	}
	printf("%d\n", ans);
	return 0;
}