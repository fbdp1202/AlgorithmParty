// baekjoon 1712 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll A, B, C;

int main() {
	scanf("%lld%lld%lld", &A, &B, &C);
	if (B < C) printf("%lld\n", A/(C-B)+1LL);
	else puts("-1");
	return 0;
}