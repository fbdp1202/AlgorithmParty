// baekjoon 3449 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;

int T;
char A[MAX_N], B[MAX_N];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ret = 0;
		scanf("%s%s", A, B);
		for (int i=0; A[i]; i++) ret += abs(A[i]-B[i]);
		printf("Hamming distance is %d.\n", ret);
	}
	return 0;
}