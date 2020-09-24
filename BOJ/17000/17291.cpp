// baekjoon 17291 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N=21;

int N;
ll dp[MAX_N];

int main() {
    scanf("%d", &N);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i=4; i<=N; i++) {
        if (i % 2) dp[i] = dp[i-1] * 2;
        else dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    printf("%lld\n", dp[N]);
    return 0;
}
