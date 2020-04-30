// baekjoon 1958 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 102;

int dp[MAX_N][MAX_N][MAX_N];
char A[MAX_N], B[MAX_N], C[MAX_N];

int main() {
	scanf("%s %s %s", A+1, B+1, C+1);
	int i, j, k;
	for (i=1; A[i]; i++) {
		for (j=1; B[j]; j++) {
			for (k=1; C[k]; k++) {
				if (A[i]==B[j] && B[j]==C[k]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				dp[i][j][k]=max(dp[i][j][k], max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1])));
			}
		}
	}
	printf("%d\n", dp[i-1][j-1][k-1]);
	return 0;
}