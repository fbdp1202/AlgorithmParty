// baekjoon 6989 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;


const int MAX_N=152;
// 최대 점수 = 100*(150*(150+1))/2 = 1132500 < 40000*32 = 1280000
const int MAX_V=40000; 

int N, K, cur, s;
int arr[MAX_N], sum[MAX_N], tsum[MAX_N][MAX_N]; // tsum(s, e)
unsigned int dp[MAX_N][MAX_V];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i-1] + arr[i];
		tsum[1][i] = tsum[1][i-1] + sum[i];
		for (int j=2; j<=i; j++)
			tsum[j][i] = tsum[j][i-1] + sum[i] - sum[j-1];
	}
	scanf("%d", &K);
	if (K > tsum[1][N]) return !printf("%d\n", K);

    dp[0][0]=1;
    for (int i=1;i<=N;i++) {
        dp[i][0]=1;
        for (int j=1;j<=i+1;j++) {
            int q = tsum[j][i]/32, r = tsum[j][i]%32;
            dp[i][q] |= (1<<r);
            if (j==1 || j==2) continue;
            for (int k=0;k<=tsum[1][j-2]/32+1;k++) {
                if(r) dp[i][k+q+1] |= (dp[j-2][k]>>(32-r));
                dp[i][k+q] |= (dp[j-2][k]<<r);
            }
        }
    }

	for (int k=K; ;k++) {
		int q = k/32, r = k%32;
		if (dp[N][q] & (1 << r)) continue;
		return !printf("%d\n", k);
	}
	return 0;
}