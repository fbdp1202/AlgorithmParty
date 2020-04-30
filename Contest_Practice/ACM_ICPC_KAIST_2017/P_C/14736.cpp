// baekjoon 14736 yechan

#include <cstdio>
#include <algorithm>
using namespace std;

int N, K, A;
int g_min = 1000000000;

int main()
{
	scanf("%d %d %d", &N, &K, &A);
	K /= A;
	for(int i = 0; i < N; i++)
	{
		int t, s;
		int div, remain, ct;
		scanf("%d %d", &t, &s);
		div = K/t;
		remain = K%t;
		ct = div*(t+s) + remain;
		if(remain == 0) ct -= s;
		g_min = min(g_min, ct);
	}
	printf("%d", g_min);
}