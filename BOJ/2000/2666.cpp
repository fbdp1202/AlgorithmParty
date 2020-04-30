// baekjoon 2666 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=21;
const ll MAX_INF=0x7FFFFFFFFFFF;
ll dp[MAX_N][MAX_N][MAX_N]; // (idx, first, second);

int N, left, right, K;
int seq[MAX_N];

ll go(int idx, int l, int r) {
	if (idx >= K) return 0;
	ll &ret = dp[idx][l][r];
	if (ret != -1) return ret;
	ret=MAX_INF;
	ret=min(ret, abs(seq[idx]-l) + go(idx+1, seq[idx], r));
	ret=min(ret, abs(seq[idx]-r) + go(idx+1, l, seq[idx]));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	scanf("%d%d", &left, &right);
	scanf("%d", &K);
	for (int i=0; i<K; i++)
		scanf("%d", &seq[i]);
	printf("%lld\n", go(0, left, right));
	return 0;
}