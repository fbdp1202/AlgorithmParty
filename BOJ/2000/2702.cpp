// baekjoon 2702 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A, B;

int gcd(int A, int B) {
	if (A % B == 0) return B;
	return gcd(B, A % B);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &A, &B);
		if (A < B) swap(A, B);
		int g = gcd(A, B);
		printf("%d %d\n", A*B/g, g);
	}
}