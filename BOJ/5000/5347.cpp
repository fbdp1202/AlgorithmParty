// baekjoon 5347 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, A, B;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a%b);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &A, &B);
		if (A < B) swap(A, B);
		int g = gcd(A, B);
		printf("%lld\n", 1LL*A*B/g);
	}
	return 0;
}