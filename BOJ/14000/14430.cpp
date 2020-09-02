// baekjoon 14430 yechan
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=302;

int N, M, x;
int dp[MAX_N][MAX_N];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            scanf("%d", &x);
            dp[i][j] = max(dp[i][j-1] + x, dp[i-1][j] + x);
        }
    }
    printf("%d\n", dp[N][M]);
    return 0;
}