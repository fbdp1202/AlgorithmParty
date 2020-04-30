// baekjoon 5724 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	while (1)
	{
		int N;
		scanf("%d", &N);
		if (!N) break;

		int ret=0;
		printf("%d\n", (N*(N+1)*(2*N+1))/6);
	}
	return 0;
}