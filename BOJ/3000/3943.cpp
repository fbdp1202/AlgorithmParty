// baekjoon 3943 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=300001;

int T, N;
ll dp[MAX_N];

ll dfs(ll num) {
	if (num < MAX_N && dp[num]) return dp[num];
	ll ret=num;
	if (num == 1) return 1;

	if (num & 1) ret = max(ret, dfs(num*3+1));
	else ret = max(ret, dfs(num/2));
	if (num < MAX_N) dp[num] = ret;
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", dfs(N));
	}
	return 0;
}