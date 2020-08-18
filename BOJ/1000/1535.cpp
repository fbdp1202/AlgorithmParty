// baekjoon 1535 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=21;
const int MAX_L=201;

int N, L[MAX_N], J[MAX_N], dp[MAX_L];

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &L[i]);
    for (int i=0; i<N; i++) scanf("%d", &J[i]);

    dp[0]=0;
    for (int i=0; i<N; i++) {
        for (int j=100; j>=0; j--) {
            if (dp[j] == -1) continue;
            dp[j+L[i]] = max(dp[j+L[i]], dp[j]+J[i]);
        }
    }
    int ret = 0;
    for (int i=0; i<100; i++)
        ret = max(ret, dp[i]);
    printf("%d\n", ret);
    return 0;
}