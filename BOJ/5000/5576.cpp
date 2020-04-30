// baekjoon 5576 yechan
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int W[10], K[10], WV, KV;
int main() {
	for (int i=0; i<10; i++)
		scanf("%d", &W[i]);
	sort(W, W+10, greater<int>());

	for (int i=0; i<10; i++)
		scanf("%d", &K[i]);
	sort(K, K+10, greater<int>());

	for (int i=0; i<3; i++) {
		WV += W[i];
		KV += K[i];
	}
	printf("%d %d\n", WV, KV);
	return 0;
}