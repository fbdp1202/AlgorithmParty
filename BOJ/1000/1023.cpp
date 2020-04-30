// baekjoon 1023 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 51;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
ll K;
ll dp[MAX_N][MAX_N*2][2]; // [StringPosition][OpenParenthesis][wrong_flag]

ll findDP(int pos, int open, int wrong) {
	if (pos == N) return wrong || open !=0;
	ll &ret = dp[pos][open+N][wrong];
	if (ret != infl) return ret;
	ret = 0;
	ret += findDP(pos+1, open+1, wrong);
	ret += findDP(pos+1, open-1, wrong || open <= 0);
	return ret;
}

void trackingParen(int pos, int open, int wrong, ll k) {
	if (pos == N) return;
	if (dp[pos+1][open+1+N][wrong] >= k) {
		if (pos == N-1 && k==2) printf(")");
		else printf("(");
		trackingParen(pos+1, open+1, wrong, k);
	}
	else {
		printf(")");
		trackingParen(pos+1, open-1, wrong || open <= 0, k - dp[pos+1][open+1+N][wrong]);
	}
}

int main() {
	memset(dp, 0x3c, sizeof(dp));
	scanf("%d%lld", &N, &K);
	findDP(0, 0, 0);
	if (K+1 > dp[0][N][0]) return !printf("-1");
	trackingParen(0, 0, 0, K+1);
	return 0;
}