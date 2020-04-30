// baekjoon 1297 yechan
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int d, x, y;
	double rx, ry, step;
	scanf("%d %d %d", &d, &x, &y);
	step = sqrt(x*x + y*y);
	rx = x * d / step;
	ry = y * d / step;
	printf("%d %d\n", (int)rx, (int)ry);
	return 0;
}