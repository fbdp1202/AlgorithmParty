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

int dfs(int left, int right) {
	int &ret = dp[left][right];
	if (ret != -1) return ret;
	if (left > right) return ret = 0;
	if (left == right) return ret = (A[left] == B[left]);
	ret = (A[left] == B[right]) + dfs(left+1, right-1) + (A[right] == B[left]);
	ans = max(ans, check[left-1] + ret + original - check[right]);
	return ret;
}

int main() {
    setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		memset(dp, -1, sizeof(dp));
		original=0;
		printf("Case #%d\n", t);
		scanf("%d", &N);
		for (int i=1; i<=N; i++)
			scanf("%d", &A[i]);
		for (int i=1; i<=N; i++)
			scanf("%d", &B[i]);
		for (int i=1; i<=N; i++) {
			if (A[i] == B[i]) {
				original++;
			}
			check[i] = original;
		}
		check[N+1] = original;

		ans = original;
		for (int i=1; i<=N; i++) {
			ans = max(ans, dfs(1, i));
			ans = max(ans, dfs(i, N));
		}
		printf("%d\n", ans);
	}
	return 0;
}