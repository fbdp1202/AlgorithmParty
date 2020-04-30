// baekjoon 9461 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100
typedef long long LL;
LL d[MAX_N+1];
int T, n;

int main()
{
	d[1]=1; d[2]=1; d[3]=1; d[4]=2; d[5]=2;
	for(int i=6; i<MAX_N+1; i++){
		d[i] += d[i-1] + d[i-5];
	}
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
	return 0;
}