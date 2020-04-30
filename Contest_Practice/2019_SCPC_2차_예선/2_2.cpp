#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=5002;

int T, N;
int original;
int check[MAX_N];
int A[MAX_N], B[MAX_N];
int dp[MAX_N][MAX_N]; // left, right
int ans;

int main() {
    setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		ans=original=0;
		printf("Case #%d\n", t);
		scanf("%d", &N);
		for (int i=1; i<=N; i++)
			scanf("%d", &A[i]);
		for (int i=1; i<=N; i++)
			scanf("%d", &B[i]);
		for (int i=1; i<=N; i++) {
			dp[i][i]=(A[i] == B[i]);
			dp[i-1][i]=(A[i-1] == B[i]) + (A[i] == B[i-1]);
			if (A[i] == B[i]) {
				original++;
			}
			check[i] = original;
		}
		check[N+1] = original;
		for (int i=1; i<=N; i++) {
			ans = max(ans, check[i-1] + dp[i][i] + original - check[i]);
			if (i > 1) ans = max(ans, check[i-2] + dp[i-1][i] + original - check[i]);
		}

		for (int i=2; i<=N-1; i++) {
			for (int j=1; j<=N-i; j++) {
				dp[j][j+i] = dp[j+1][j+i-1] + (A[j] == B[j+i]) + (A[j+i] == B[j]);
				ans = max(ans, check[j-1] + dp[j][j+i] + original - check[j+i]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}