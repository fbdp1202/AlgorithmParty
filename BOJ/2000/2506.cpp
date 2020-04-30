// baekjoon 2506 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, X, cnt, result;
int main() {
	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%d", &X);
		if (X) cnt++;
		else cnt = 0;
		result += cnt;
	}
	printf("%d\n", result);
	return 0;
}