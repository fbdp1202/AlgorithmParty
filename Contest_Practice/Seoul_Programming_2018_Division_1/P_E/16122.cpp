// baekjoon 16122 yechan
#include <cstdio>
#include <algorithm>

using namespace std;
#define DIV_NUM 998244353
#define MAX_LEN 300000

typedef long long unsigned int LL;

int g_N, g_M;
int d[MAX_LEN + 1];
int nd[MAX_LEN + 1];

LL fac[MAX_LEN+1];

LL factorial(int n)
{
	if(n == 0) return 1;
	if(fac[n]) return fac[n];
	LL tmp = n*factorial(n-1);
	fac[n] = tmp;
	return tmp;
}

LL combination(int n, int r){
	return factorial(n)/factorial(n-r)/factorial(r)%DIV_NUM;
}

int main()
{
	int i, j;
	scanf("%d %d", &g_N, &g_M);
	int x = g_M+(g_N+1)/2;
	if(x < 0 || x > g_N) printf("0");
	else printf("%lld",combination(g_N, x));
}