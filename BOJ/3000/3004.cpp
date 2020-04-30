// baekjoon 3004 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int A = N/2+1;
	int B = (N+1)/2+1;
	printf("%d\n", A*B);
	return 0;
}