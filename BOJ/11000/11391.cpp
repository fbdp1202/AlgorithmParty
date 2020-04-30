// baekjoon 11391 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, K;

int main() {
	scanf("%d%d", &N, &K);
	int cnt = 0;
	for (int i=0; i<(1<<K); i++) {
		for (int j=0; j<(1<<(N-K-1)); j++) {
			printf("%d %d ", cnt, (1<<(N))-1-cnt);
			cnt++;
		}
		puts("");
	}
	return 0;
}