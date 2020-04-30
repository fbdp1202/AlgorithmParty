// baekjoon 2959 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A[4];

int main()
{
	for (int i=0; i<4; i++)
		scanf("%d", &A[i]);

	int ret = 0;
	ret = max(ret, min(A[0], A[1])*min(A[2], A[3]));
	ret = max(ret, min(A[0], A[2])*min(A[1], A[3]));
	ret = max(ret, min(A[0], A[3])*min(A[1], A[2]));
	printf("%d\n", ret);
	return 0;
}