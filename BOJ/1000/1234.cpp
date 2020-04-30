// baekjoon 1234 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, R, G, B;
ll dp[11][101][101][101];

ll dfs(int n, int r, int g, int b)
{
	printf("dfs(%d, %d, %d, %d)\n", n, r, g, b);
	if (n == 0) return 1;

	ll &ret = dp[n][r][g][b];
	if (ret != -1) return ret;

	ret = 0;
	if (n%3 == 0) {
		if (r >= n/3 && g >= n/3 && b >= n/3) {
			ret += dfs(n-1, r-n/3, g-n/3, b-n/3);
		}
	}
	if (n%2 == 0) {
		if (r >= n/2 && g >= n/2) {
			ret += dfs(n-1, r-n/2, g-n/2, b);
		}
		if (r >= n/2 && b >= n/2) {
			ret += dfs(n-1, r-n/2, g, b-n/2);
		}
		if (g >= n/2 && b >= n/2) {
			ret += dfs(n-1, r, g-n/2, b-n/2);
		}
	}
	if (r >= n) {
		ret += dfs(n-1, r-n, g, b);
	}
	if (g >= n) {
		ret += dfs(n-1, r, g-n, b);
	}
	if (b >= n) {
		ret += dfs(n-1, r, g, b-n);
	}
	return ret;
}

int main()
{
	memset(dp, 0xFF, sizeof(dp));
	scanf("%d%d%d%d", &N, &R, &G, &B);
	printf("%lld\n", dfs(N, R, G, B));
	return 0;
}