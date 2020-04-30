// baekjoon 2515 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N=300001;

int N, S;
P data[MAX_N];
ll dp[MAX_N];

int main() {
	scanf("%d%d", &N, &S);
	for (int i=1; i<=N; i++)
		scanf("%d%d", &data[i].first, &data[i].second);
	sort(data+1, data+N+1);
	data[0]=P(-1e9, 0);
	dp[0]=0;

	for (int i=1; i<=N; i++) {
		int idx = lower_bound(data, data+N+1, P(data[i].first-S+1, -1e9)) - data;
		idx--;
		dp[i] = max(dp[idx]+data[i].second, dp[i-1]);
	}
	printf("%lld\n", dp[N]);
	return 0;
}