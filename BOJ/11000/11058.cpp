#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N=101;
int N;
ll dp[MAX_N];

int main() {
    scanf("%d", &N);
    dp[1]=1, dp[2]=2, dp[3]=3, dp[4]=4, dp[5]=5;
    for (int i=4; i<MAX_N; i++) {
        ll step = dp[i-3];
        for (int j=0; i+j<MAX_N; j++) {
            dp[i+j] = max(dp[i+j], step * (j+2));
        }
    }
    printf("%lld\n", dp[N]);
    return 0;
}