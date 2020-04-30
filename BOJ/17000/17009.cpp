// baekjoon 17009 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int A, B;
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	A = x*3 + y*2 + z;
	scanf("%d%d%d", &x, &y, &z);
	B = x*3 + y*2 + z;
	if (A == B) printf("T\n");
	else if (A > B) printf("A\n");
	else printf("B\n");
	return 0;
}