// baekjoon 10474 yechan
#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B;
	while (1) {
		scanf("%d%d", &A, &B);
		if (!A && !B) break;
		printf("%d %d / %d\n", A/B, A%B, B);
	}
	return 0;
}