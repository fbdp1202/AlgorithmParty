// baekjoon 14495 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=117;

int N;
ll dp[MAX_N];

int main() {
    scanf("%d", &N);
    dp[1]=dp[2]=dp[3]=1;
    for (int i=4; i<=N; i++)
        dp[i] = dp[i-1]+dp[i-3];
    printf("%lld\n", dp[N]);
    return 0;
}