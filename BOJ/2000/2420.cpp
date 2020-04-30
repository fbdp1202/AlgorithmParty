// baekjoon 2420 yechan
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll N, M;
int main() {
	scanf("%lld %lld", &N, &M);
	printf("%lld\n", (ll)abs(N-M));
	return 0;
}