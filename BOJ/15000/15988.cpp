#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=1000001;
const ll DIV_NUM=1000000009;

ll T, N, dp[MAX_N];

int main() {
    dp[0]=dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for (int i=4; i<MAX_N; i++)
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%DIV_NUM;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &N);
        printf("%d\n", dp[N]);
    }
    return 0;
}