// baekjoon 2965 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int A, B, C, rst;
int main()
{
	scanf("%d %d %d", &A, &B, &C);
	printf("%d", max(B-A-1, C-B-1));
	return 0;
}