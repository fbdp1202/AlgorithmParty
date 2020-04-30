// baekjoon 10093 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

long long A, B;

int main()
{
	scanf("%lld%lld", &A, &B);
	if (A > B) swap(A, B);
	printf("%lld\n", max(B-A-1, 0LL));
	for (long long i=A+1; i<B; i++) {
		printf("%lld ", i);
	}
	puts("");
	return 0;
}