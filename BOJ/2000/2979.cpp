// baekjoon 2979 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int cost[4], x, y, track[101];

int main()
{
	for (int i=1; i<4; i++)
		scanf("%d", &cost[i]);

	for (int i=0; i<3; i++) {
		scanf("%d%d", &x, &y);
		for (int j=x; j<y; j++)
			track[j]++;
	}

	int ret = 0;
	for (int i=1; i<101; i++)
		ret += cost[track[i]]*track[i];

	printf("%d\n", ret);
	return 0;
}