// baekjoon 11758 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int cross(int x1, int y1, int x2, int y2) {
	return x1*y2-x2*y1;
}

int main() {
	int x1, y1, x2, y2, x3, y3;
	scanf("%d%d %d%d %d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	int ret = cross(x2-x1, y2-y1, x3-x1, y3-y1);
	if (ret > 0) puts("1");
	else if (ret < 0) puts("-1");
	else puts("0");
	return 0;
}