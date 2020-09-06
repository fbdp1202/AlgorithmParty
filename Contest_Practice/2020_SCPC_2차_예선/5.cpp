#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=301;
int T, N;
P pos[MAX_N];
int dp[MAX_N];

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    dp[0]=dp[1]=dp[2]=dp[3]=0;
    dp[4]=1;

    for (int i=5; i<MAX_N; i++)
        dp[i] = dp[(i+1)/2] + 2;

    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);
        scanf("%d", &N);
        for (int i=0; i<N; i++)
            scanf("%d%d", &pos[i].first, &pos[i].second);
        printf("%d\n", dp[N]);
    }
    return 0;
}