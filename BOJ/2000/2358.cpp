// baekjoon 2358 yechan
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int N, X, Y, ret;

int main()
{
	scanf("%d", &N);
	map<int, int> x, y;
	for (int i=0; i<N; i++) {
		scanf("%d %d", &X, &Y);
		if (++x[X] == 2) ret++;
		if (++y[Y] == 2) ret++;
	}
	printf("%d\n", ret);
	return 0;
}