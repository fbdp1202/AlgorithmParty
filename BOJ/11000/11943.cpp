// baekjoon 11943 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int a,b,c,d;

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", min(a+d, b+c));
	return 0;
}