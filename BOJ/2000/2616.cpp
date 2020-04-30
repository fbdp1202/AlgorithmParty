// baekjoon 2616 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N=50001;
int N, P, x, ret, data[MAX_N];
int dp[3][MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &x);
		data[i]=data[i-1]+x;
	}
	scanf("%d", &P);
	for (int i=0; i<3; i++) {
		for (int j=1*P; j<=N; j++) {
			if (i==0) dp[i][j]=max(dp[i][j-1], data[j]-data[j-P]);
			else  dp[i][j]=max(dp[i][j-1], dp[i-1][j-P]+data[j]-data[j-P]);
			ret=max(ret, dp[i][j]);
		}
	}
	printf("%d\n", ret);
	return 0;
}