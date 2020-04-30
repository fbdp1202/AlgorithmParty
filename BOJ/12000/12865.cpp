// baekjoon 12865 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=101;
const int MAX_K=100001;

int N, K, dp[MAX_K];
P stuff[MAX_N];

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		stuff[i] = P(x,y);
	}
	for (int i=0; i<N; i++)
		for (int j=MAX_K-1-stuff[i].first; j>=0; j--)
			dp[j+stuff[i].first] = max(dp[j+stuff[i].first], dp[j]+stuff[i].second);

	int ret = 0;
	for (int j=0; j<=K; j++)
		ret = max(ret, dp[j]);
	printf("%d\n", ret);
	return 0;
}