// baekjoon 1038 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, acum, dp[11][10], dpa[11][10];

void tracking(int P, int N)
{
	if(dpa[P][P-1] > N)
		tracking(P-1, N), return;
	
	for(int i=P-1; i<10; i++){
		if(dpa[P][i] == N){
			for(int j=0; j<P; j++)
				printf("%d", i-j);
			return;
		}
		if(dpa[P][i] > N){
			printf("%d", i);
			tracking(P-1, N-dpa[P][i-1]+dpa[P-1][P-2]-1);
			return;
		}
	}
}

int main()
{
	dp[0][0] = 1;	dp[1][0] = 1;
	scanf("%d", &N); 	N++;
	for(int i=1; i<11; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<j; k++)
				dp[i][j] += dp[i-1][k];
			acum += dp[i][j];
			if(dp[i][j])
				dpa[i][j] = acum;
		}
	}
	if(dpa[10][9] < N) 	printf("-1");
	else				tracking(10, N);
}