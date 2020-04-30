// baekjoon 2720 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;

int main()
{
	scanf("%d", &N);
	while (N--)
	{
		int money;
		scanf("%d", &money);
		printf("%d ", money/25); money%=25;
		printf("%d ", money/10); money%=10;
		printf("%d ", money/5); money%=5;
		printf("%d\n", money);
	}
	return 0;
}