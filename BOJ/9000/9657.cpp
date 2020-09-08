#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;

int N, dp[MAX_N];

int main() {
    scanf("%d", &N);
    dp[1]=dp[3]=dp[4]=1;
    for (int i=5; i<=N; i++)
        dp[i] = !dp[i-4] || !dp[i-3] || !dp[i-1];
    puts(dp[N] ? "SK" : "CY");
    return 0;
}