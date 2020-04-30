// baekjoon 3009 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int X[3], Y[3];

int main()
{
	for (int i=0; i<3; i++)
		scanf("%d%d", &X[i], &Y[i]);

	sort(X, X+3);
	sort(Y, Y+3);

	if (X[0] != X[1]) printf("%d ", X[0]);
	else printf("%d ", X[2]);
	if (Y[0] != Y[1]) printf("%d\n", Y[0]);
	else printf("%d\n", Y[2]);

	return 0;
}