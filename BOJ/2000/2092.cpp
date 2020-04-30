// baekjoon 2092 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_A=4001;
const int MAX_T=201;
const int DIV_NUM=1e6;

int T, A, S, B;
int cnt[MAX_T];
int dp[MAX_T][MAX_A];

int dfs(int here, int num) {
	if (num == 0) return 1;
	if (T < here) return 0;
	int &ret = dp[here][num];
	if (ret != -1) return ret;

	ret = 0;
	for (int i=0; i<=min(cnt[here], num); i++)
		ret = (ret + dfs(here+1, num-i))%DIV_NUM;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d%d", &T, &A, &S, &B);
	for (int i=0; i<A; i++) {
		int x; scanf("%d", &x);
		cnt[x]++;
	}

	int ret = 0;
	for (int i=S; i<=B; i++)
		ret = (ret + dfs(1, i))%DIV_NUM;
	printf("%d\n", ret);
	return 0;
}