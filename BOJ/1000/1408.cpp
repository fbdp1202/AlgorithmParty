// baekjoon 1408 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int x1, y1, z1;
int x2, y2, z2;
int x3, y3, z3;

int main()
{
	scanf("%02d:%02d:%02d", &x1, &y1, &z1);
	scanf("%02d:%02d:%02d", &x2, &y2, &z2);
	int t1 = x1*3600 + y1*60 + z1;
	int t2 = x2*3600 + y2*60 + z2;
	if (t1 > t2) t2 += 24*3600;
	int t3 = t2 - t1;
	x3 = t3 / 3600;
	y3 = (t3 % 3600)/60;
	z3 = t3 % 60;
	printf("%02d:%02d:%02d\n", x3, y3, z3);
	return 0;
}