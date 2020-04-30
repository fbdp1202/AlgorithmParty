// baekjoon 8394 yechan
#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	if (N == 1) return !printf("1\n");
	if (N == 2) return !printf("2\n");
	int ppv = 1, pv = 2, curr;
	for (int i=3; i<=N; i++) {
		curr = (ppv + pv)%10;
		ppv = pv;
		pv = curr;
	}
	printf("%d\n", curr);
	return 0;
}