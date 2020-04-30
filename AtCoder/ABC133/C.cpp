#include <cstdio>
#include <algorithm>
using namespace std;

const int DIV_NUM=2019;

int A, B;

int main()
{
	scanf("%d%d", &A, &B);
	int minA, minB;
	if (B-A >= DIV_NUM) {
		minA=0, minB=DIV_NUM-1;
	} else {
		minA = A%DIV_NUM;
		minB = B%DIV_NUM;
		if (minA > minB) minB += DIV_NUM;
	}

	int ret=DIV_NUM;
	for (int i=minA; i<=minB; i++)
		for (int j=i+1; j<=minB; j++)
			ret = min(ret, (i*j)%DIV_NUM);
	printf("%d\n", ret);
	return 0;
}