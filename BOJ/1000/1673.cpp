// baekjoon 1673 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, K;

int main()
{
	while (scanf("%d%d", &N, &K) != -1) {
		int ret = 0;
		while (K <= N) {
			ret += K*(N/K);
			N = N/K + N%K;
		}
		ret += N;
		printf("%d\n", ret);
	}
	return 0;
}