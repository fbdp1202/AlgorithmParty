#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;

int N, dp[MAX_N];

int dfs(int here) {
    int &ret = dp[here];
    if (ret != -1) return ret;

    ret = 0;
    if (here>=3) ret |= !dfs(here-3);
    ret |= !dfs(here-1);
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    dp[0]=1;
    puts(dfs(N) ? "SK" : "CY");
    return 0;
}