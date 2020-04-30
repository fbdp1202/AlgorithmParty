// baekjoon 16283 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, n, w;

int main()
{
	scanf("%d%d%d%d", &a, &b, &n, &w);
	if (a == b) {
		if (n == 2 && a+b == w) return !printf("1 1\n");
		return !printf("-1\n");
	}
	int x, y;
	if ((w-a*n)%(b-a)) return !printf("-1\n");
	y = (w-a*n)/(b-a);
	x = n-y;
	if (x <= 0 || y <= 0) return !printf("-1\n");
	printf("%d %d\n", x, y);
	return 0;
}