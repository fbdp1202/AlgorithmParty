// baekjoon 1057 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int N, K, L, rst;
int main()
{
	scanf("%d %d %d", &N, &K, &L);
	while(1){
		rst++;
		if(abs(K-L)==1 && min(K,L)%2) break;
		N = (N+1)/2;
		K = (K+1)/2;
		L = (L+1)/2;
	}
	printf("%d", rst);
	return 0;
}