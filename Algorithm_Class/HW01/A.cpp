// postech hw01-A fbdp1202(yechan)
#include <cstdio>
using namespace std;

int main() {
	int N;
	long long A, B;
	scanf("%d", &N);
	while (N--) {
		scanf("%lld%lld", &A, &B);
		printf("%lld\n", A+B);
	}
	return 0;
}