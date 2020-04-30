// baekjoon 2631 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 201
int N, d[MAX_N], dp[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &d[i]);

	int max_len = 1;
	for(int i=0; i<N; i++)
	{
		int tmp = 1;
		for(int j=0; j<i; j++)
			if(d[j] < d[i]) tmp = max(tmp, dp[j]+1);
		dp[i] = tmp;
		max_len = max(max_len, tmp);
	}
	printf("%d", N-max_len);
}