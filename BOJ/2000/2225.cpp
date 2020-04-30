// baekjoon 2225 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_INPUT_SIZE 201
#define DIV_NUM 1000000000

typedef long long unsigned LL;

int N, K;
LL dp[MAX_INPUT_SIZE][MAX_INPUT_SIZE]; // K, N;


int main()
{
	scanf("%d %d", &N, &K);
	dp[0][0] = 1;
	for(int i=1; i<=K; i++){
		for(int j=0; j<=N; j++){
			for(int z=0; z<=j; z++)
				dp[i][j] += dp[i-1][j-z];
			dp[i][j] = dp[i][j]%DIV_NUM;
		}
	}
	
	printf("%lld", dp[K][N]);
}