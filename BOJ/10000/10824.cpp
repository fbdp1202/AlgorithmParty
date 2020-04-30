// baekjoon 10824 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll A, B, C, D, tmp;
int main() {
	scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
	int numlenB=1, numlenD=1;
	tmp=B;
	while (tmp) tmp/=10, numlenB*=10;
	tmp=D;
	while (tmp) tmp/=10, numlenD*=10;
	printf("%lld\n", A*numlenB+B+C*numlenD+D);
	return 0;
}