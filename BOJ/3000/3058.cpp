// baekjoon 3058 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int ret = 0;
		int minV = 1e9;
		int x;
		for (int i=0; i<7; i++) {
			scanf("%d", &x);
			if (!(x & 1)) minV = min(minV, x), ret += x;
		}
		printf("%d %d\n", ret, minV);
	}
	return 0;
}