// baekjoon 5582 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 4002

char A[MAX_N], B[MAX_N];
int dp[MAX_N][MAX_N], rst;

int main() {
	scanf("%s %s", A+1, B+1);
	for (int i=1; A[i]; i++) {
		for (int j=1; B[j]; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i-1][j-1]+1;
				rst = max(rst, dp[i][j]);
			}
		}
	}
	printf("%d\n", rst);
	return 0;
}