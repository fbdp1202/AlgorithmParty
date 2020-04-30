// baekjoon 17520 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int DIV_NUM = 16769023;

typedef long long ll;

int N;

ll pow10(int a, int b) {
	if (b == 0) return 1;
	ll ret = pow10(a, b/2);
	ret = (ret * ret)%DIV_NUM;
	if (b & 1) ret = (ret * a)%DIV_NUM;
	return ret;
}

int main() {
	scanf("%d", &N);
	printf("%lld\n", pow10(2, (N+1)/2));
	return 0;
}