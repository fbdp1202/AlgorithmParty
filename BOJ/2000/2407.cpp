// baekjoon 2407 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;
const ll maxNum = 1e17;

struct llll{
	ll high = 0;
	ll low = 0;
	llll():llll(0,0){}
	llll(ll high, ll low):high(high), low(low){}
};

llll operator+(const llll a, const llll b) {
	llll c;
	if (a.low + b.low < maxNum) {
		c.low = a.low + b.low;
		c.high = a.high + b.high;
	}
	else {
		c.low = (a.low + b.low)%maxNum;
		c.high = a.high + b.high + (a.low + b.low)/maxNum;
	}
	return c;
}


llll dp[101][101];

int main() {
	dp[1][0].low=dp[1][1].low=1;
	for (int i=2; i<101; i++) {
		for (int j=0; j<=i; j++)
			dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
	}
	int N, M;
	scanf("%d%d", &N, &M);
	if (dp[N][M].high) {
		printf("%lld",dp[N][M].high);
		printf("%017lld\n", dp[N][M].low);
	} else {
		printf("%lld\n", dp[N][M].low);
	}
	return 0;
}