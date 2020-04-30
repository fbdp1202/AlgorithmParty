// baekjoon 1834 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll N;
	scanf("%lld", &N);
	printf("%lld", (N*N*N-N)/2);
	return 0;
}