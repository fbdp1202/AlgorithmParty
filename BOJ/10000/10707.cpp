// baekjoon 10707
#include <cstdio>
#include <algorithm>
using namespace std;

int XA, YB, YC, YD, P;
int xc, yc;

int main()
{
	scanf("%d %d %d %d %d", &XA, &YB, &YC, &YD, &P);
	xc = P*XA;
	yc = YB;
	P -= YC;
	if(P > 0) yc += YD*P;
	int result = min(xc, yc);
	printf("%d", result);
}