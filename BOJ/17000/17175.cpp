// baekjoon 17175 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
const ll DIV_NUM = 1000000007;

int N;

ll dp[55];

ll dfs(int here) {
	ll &ret = dp[here];
	if (ret != -1) return ret;
	return ret = (1 + dfs(here-1) + dfs(here-2)) % DIV_NUM;
}

int main()
{
	memset(dp, 0xFF, sizeof(dp));
	scanf("%d", &N);
	for (int i=0; i<2; i++)
		dp[i] = 1;
	printf("%lld\n", dfs(N));
	return 0;
}