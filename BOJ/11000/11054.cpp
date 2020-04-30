// baekjoon 11054 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001

int N, A[MAX_N], dpn[MAX_N], dpp[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &A[i]);

	dpn[0] = 1; dpp[0] = 1;

	int max_len =1;

	for(int i=0; i<N; i++){
		int tmpp = 1; int tmpn = 1;
		for(int j=0; j<i; j++){
			if(A[j] < A[i]) tmpp = max(tmpp, dpp[j]+1);
			if(A[j] > A[i]) tmpn = max(tmpn, max(dpn[j]+1, dpp[j]+1));
		}
		dpn[i] = tmpn;
		dpp[i] = tmpp;
		max_len = max(max_len, max(tmpp, tmpn));
	}
	printf("%d", max_len);
	return 0;
}