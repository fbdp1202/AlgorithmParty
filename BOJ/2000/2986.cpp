// baekjoon 2986 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, maxV=1;
int main() {
	scanf("%d", &N);
	for (int i=2; i*i<=N; i++) {
		if (N%i==0) maxV=max(maxV, max(i, N/i));
	}
	printf("%d\n", N-maxV);
	return 0;
}