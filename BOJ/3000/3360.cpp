// baekjoon 3360 yechan
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=100001;
const int MAX_INF=1e9;

int N, dp[MAX_N];

int dfs(int here) {
    int &ret = dp[here];
    if (ret != -1) return ret;
    ret = MAX_INF;
    if (here >= 7) ret = min(ret, dfs(here-7) + 1);
    if (here >= 5) ret = min(ret, dfs(here-5) + 1);
    if (here >= 2) ret = min(ret, dfs(here-2) + 1);
    if (here >= 1) ret = min(ret, dfs(here-1) + 1);

    return ret;
}

int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    printf("%d\n", dfs(N));
    return 0;
}