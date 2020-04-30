// baekjoon 1598 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int A, B;
	scanf("%d%d", &A, &B);
	A--, B--;
	int x1, y1, x2, y2;
	x1 = A/4, y1 = A % 4;
	x2 = B/4, y2 = B % 4;
	printf("%d\n", abs(x1-x2) + abs(y1-y2));
	return 0;
}