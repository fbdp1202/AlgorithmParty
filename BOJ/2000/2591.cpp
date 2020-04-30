// baekjoon 2591 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int lenCard;
char card[41];
ll dp[41];

ll countCard(int pos) {
	if (pos == lenCard) return 1;
	ll &ret = dp[pos];
	if (ret != -1) return dp[pos];
	ret = 0;
	if (card[pos] == '0') return 0;

	ret += countCard(pos+1);
	if (pos + 1 != lenCard) {
		int num = (card[pos]-'0')*10+(card[pos+1]-'0');
		if (num <= 34) ret += countCard(pos+2);
	}
	return ret;
}

int main() {
	fill(dp, dp+41, -1);
	scanf("%s", card);
	for (lenCard=0; card[lenCard]; lenCard++);
	printf("%lld\n", countCard(0));
	return 0;
}