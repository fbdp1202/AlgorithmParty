// baekjoon 5557 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 101
int N, nlist[MAX_N];
long long dp[MAX_N][21];

long long find_equation(int n, int num)
{
	if(n == N-1 && num == nlist[N-1]) return 1;
	if(n == N-1 && num != nlist[N-1]) return 0;
	if(~dp[n][num]) return dp[n][num];
	long long tmp = 0;
	if(num + nlist[n] <= 20) tmp += find_equation(n+1, num + nlist[n]);
	if(num - nlist[n] >= 0)  tmp += find_equation(n+1, num - nlist[n]);
	dp[n][num] = tmp;
	return tmp;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &nlist[i]);
	for(int i=0; i<N; i++)
		for(int j=0; j<21; j++)
			dp[i][j] = -1;

	printf("%lld", find_equation(1,nlist[0]));
	return 0;
}