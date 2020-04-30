// baekjoon 2355 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define f(n) ( ((n)*(n+1))/2LL )
typedef long long ll;

ll A, B, result;

int main() {
	scanf("%lld%lld", &A, &B);
	if (A > B) swap(A, B); // A <= B

	if (0 <= A) {
		result = f(B)-f(A-1);
	} else if (B <= 0) { // A < B <= 0
		result = -f(-A) + f(-B-1);
	} else { // A <= 0, B >=0
		result = f(B) - f(-A);
	}
	printf("%lld\n", result);
	return 0;
}