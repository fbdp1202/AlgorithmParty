#include <bits/stdc++.h>
using namespace std;

const int MAX_N=11;

int N;
int dp[MAX_N];

int dfs(int here) {
    int &ret = dp[here];
    if (ret != -1) return ret;
    ret = 0;
    for (int i=1; i<=here/2; i++)
        ret = max(ret, i*(here-i) + dfs(i) + dfs(here-i));
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    dp[0] = dp[1] = 0;
    scanf("%d", &N);
    printf("%d\n", dfs(N));
    return 0;
}