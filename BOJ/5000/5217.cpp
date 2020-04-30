// baekjoon 5217 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		printf("Pairs for %d:", N);
		if (N > 2) printf(" %d %d", 1, N-1);
		for (int i=2; i<(N+1)/2; i++) {
			printf(", %d %d", i, N-i);
		}
		puts("");
	}
	return 0;
}