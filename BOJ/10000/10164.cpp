// baekjoon 10164 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, K;
long long dp[16][16];

int main(){
	long long result = 0;
	scanf("%d %d %d", &N, &M, &K);
	int py = (K+M-1)/M;	int px = (K-1)%M+1;
	int ny = N-py+1;	int nx = M-px+1;
	if(K==0){
		py = 0, px =0, ny = N, nx= M;
	}
	// printf("%d %d %d %d\n", py,px,ny,nx);
	dp[0][0] = 1;
	dp[1][1] = 1;
	for(int i=1; i<=15; i++){
		for(int j=1; j<=15; j++){
			dp[i][j] += dp[i-1][j] + dp[i][j-1];
		}
	}
	result = dp[py][px] * dp[ny][nx];
	printf("%lld", result);
}