// baekjoon 11568 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1001;
const int MAX_INF=2e9;

int N, data[MAX_N], LIS[MAX_N];

int main() {
	scanf("%d", &N);
	fill(LIS, LIS+N+1, MAX_INF);
	for (int i=0; i<N; i++) {
		int x;
		scanf("%d", &x);
		int idx = lower_bound(LIS, LIS+N, x) - LIS;
		LIS[idx] = x;
	}
	for (int i=0; i<N+1; i++) {
		if (LIS[i] == MAX_INF) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}