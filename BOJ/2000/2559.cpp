// baekjoon 2559 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;

int N, K, arr[MAX_N];

int main() {
	scanf("%d%d", &N, &K);
	for (int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
		arr[i] += arr[i-1];
	}
	int ret = -1e9;
	for (int i=K; i<=N; i++) {
		ret = max(ret, arr[i]-arr[i-K]);
	}
	printf("%d\n", ret);
	return 0;
}