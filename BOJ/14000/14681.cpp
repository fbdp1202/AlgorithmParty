// baekjoon 14681 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	if (x > 0 && y > 0) puts("1");
	if (x < 0 && y > 0) puts("2");
	if (x < 0 && y < 0) puts("3");
	if (x > 0 && y < 0) puts("4");
	return 0;
}