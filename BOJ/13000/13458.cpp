// baekjoon 13458 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000001

int N, A[MAX_N], B, C;
long long result;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);

	scanf("%d %d", &B, &C);

	for (int i=0; i<N; i++) {
		A[i]-=B;
		result++;
		if (A[i] > 0)
			result += (A[i]+C-1)/C;
	}
	printf("%lld", result);
	return 0;
}