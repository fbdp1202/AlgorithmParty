// baekjoon 4504 yechan
#include <cstdio>
#include <algorithm>

using namespace std;

int N, x;
int main() {
	scanf("%d", &N);
	while (1) {
		scanf("%d", &x);
		if (!x) break;
		if (x%N == 0) printf("%d is a multiple of %d.\n", x, N);
		else printf("%d is NOT a multiple of %d.\n", x, N);
	}
	return 0;
}