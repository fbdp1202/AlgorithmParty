// baekjoon 1735 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A, B, C, D, x, y, d;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main()
{
	scanf("%d%d%d%d", &A, &B, &C, &D);
	x = (A*D + B*C);
	y = (B*D);
	d = gcd(x, y);
	printf("%d %d\n", x/d, y/d);
	return 0;
}