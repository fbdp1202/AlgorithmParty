#include <bits/stdc++.h>
using namespace std;

const int MAX_N=50001;
int N, dp[MAX_N];


int main() {
    fill(dp, dp+50001, 1e9);
    dp[0]=0;
    for (int p=2; p<MAX_N; p++)
        for (int i=1; i*i<=p; i++)
            dp[p] = min(dp[p], dp[p-i*i]+1);

    scanf("%d", &N);
    printf("%d\n", dp[N]);
    return 0;
}