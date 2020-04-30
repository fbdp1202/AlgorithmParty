// baekjoon 10942 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 2001
int N, M, arr[MAX_N], dp[MAX_N], dpn[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
		scanf("%d", &arr[i]);

	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<N; j++){
			if(i-j < 1 || i+j > N) break;
			if(arr[i-j] == arr[i+j]) dp[i]++;
			else break;
		}
		for(int j=0; j<N; j++){
			if(i-j < 1 || i+j+1 > N) break;
			if(arr[i-j] == arr[i+j+1]) dpn[i]++;
			else break;
		}
	}
	scanf("%d", &M);
	for(int i=0; i<M; i++)
	{
		int S,E;
		scanf("%d %d", &S, &E);
		if((S+E)%2==1) printf("%d\n", dpn[(S+E)/2] >= (E-S+1)/2);
		else printf("%d\n",dp[(S+E)/2] >= ((E-S)/2+1));
	}
}