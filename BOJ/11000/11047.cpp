// baekjoon 11047 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=11;
int N, K, coin[MAX_N], ret;

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++)
		scanf("%d", &coin[i]);

	for (int i=N-1; i>=0; i--) {
		ret += K/coin[i];
		K %= coin[i];
	}
	printf("%d\n", ret);
	return 0;
}