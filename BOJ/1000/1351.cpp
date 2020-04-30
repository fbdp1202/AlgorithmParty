// baekjoon 1351 yechan
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
ll N, P, Q;
map<ll, ll> dp;

ll dfs(ll a) 
{
	if (a == 0) return 1;
	if (dp[a]) return dp[a];
	return dp[a] = dfs(a/P)+dfs(a/Q);
}

int main() {
	scanf("%lld%lld%lld", &N, &P, &Q);
	printf("%lld", dfs(N));
	return 0;
}