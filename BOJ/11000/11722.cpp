// baekjoon 11722 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001

int N;
int A[MAX_N];
int cache[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &A[i]);

	int max_len = 1;
	cache[0] = 1;
	for(int i=0; i<N; i++){
		int tmp = 1;
		for(int j=0; j<i; j++)
			if(A[j] > A[i]) 
				tmp = max(tmp, cache[j]+1);
		cache[i] = tmp;
		max_len = max(tmp, max_len);
	}
	printf("%d\n", max_len);
}