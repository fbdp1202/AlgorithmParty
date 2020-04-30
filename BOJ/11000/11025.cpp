// baekjoon 11025 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	int R=0;
	for (int i=2; i<=N; i++)
		R = (R+M) % i;
	printf("%d\n", R + 1);
	return 0;
}