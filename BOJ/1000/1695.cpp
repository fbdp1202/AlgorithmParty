// baekjoon 1695 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 5002

int N, dp[MAX_N][MAX_N];
int ans, arr[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &arr[i]);

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			if (arr[i] == arr[N-j+1]) dp[i][j] = dp[i-1][j-1]+1;
			dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
		}
	}
	printf("%d\n", N-dp[N][N]);
	return 0;
}