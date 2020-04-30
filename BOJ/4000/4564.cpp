// baekjoon 4564 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int game(int x) {
	int ret = 1;
	while (x) {
		ret *= x % 10;
		x/=10;
	}
	return ret;
}

int main()
{
	int N;
	while (1)
	{
		scanf("%d", &N);
		if (!N) break;
		while (N >= 10) {
			printf("%d ", N);
			N = game(N);
		}
		printf("%d\n", N);
	}
	return 0;
}