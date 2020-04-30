// baekjoon 16432 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001
int N, M, tmp, prev;
int give[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &M);
		if( M >= 3 ) prev = 0;
		for(int j=0; j<M; j++){
			scanf("%d", &tmp);
		}
	}
	if(result)
		for(int i=1; i<=N; i++)
			printf("%d\n", give[i]);
	else printf("-1");
	return 0;
}