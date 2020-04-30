// baekjoon 1121 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=51;
const int MAX_K=11;
const int MAX_L=50001;
const int MAX_V=500001;

int N, K, arr[MAX_N];
ll dp[MAX_K][MAX_V];
ll sum[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &K);
	sort(arr+1, arr+N+1);

	for (int i=1; i<=N; i++)
		sum[i] = sum[i-1] + arr[i];

	dp[0][0]=1;
	for (int i=1; i<=N; i++) {
		for (int j=min(K,i)-1; j>=0; j--) {
			for (int k=sum[j]; k<=min(sum[i]-sum[i-j-1], 1LL*MAX_V-1-arr[i]); k++) {
				if (j == K-1 && k <= arr[i]) continue;
				if (k+arr[i])
				dp[j+1][k+arr[i]] += dp[j][k];
			}
		}
	}
	ll ret = 0;
	for (int i=0; i<MAX_V; i++)
		ret += dp[K][i];

	printf("%lld\n", ret);
	return 0;
}