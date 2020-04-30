// baekjoon 10818 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, maxV=-1000001, minV=1000001, x;
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &x);
		maxV = max(maxV, x);
		minV = min(minV, x);
	}
	printf("%d %d\n", minV, maxV);
	return 0;
}