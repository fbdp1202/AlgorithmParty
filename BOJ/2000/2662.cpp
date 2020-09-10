// baekjoon 2662 yechan
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=301;
const int MAX_M=21;

int N, M;
int cost[MAX_N][MAX_M];
int dp[MAX_N][MAX_M];

int dfs(int money, int company) {
    int &ret = dp[money][company];
    if (money == 0) return ret = 0;
    if (company == 0) return ret = cost[money][company];
    if (ret != -1) return ret;

    ret = 0;
    for (int i=0; i<=money; i++)
        ret = max(ret, cost[i][company] + dfs(money-i, company-1));
    return ret;
}

void tracking(int money, int company) {
    if (company == 0) {
        printf("%d ", money);
        return;
    }
    for (int i=0; i<=money; i++) {
        if (dp[money-i][company-1] == -1) continue;
        if (cost[i][company] + dp[money-i][company-1] == dp[money][company]) {
            tracking(money-i, company-1);
            printf("%d ", i);
            return;
        }
    }
}

int main() {
    memset(dp, -1, sizeof(dp));

    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) {
        int c; scanf("%d", &c);
        for (int j=0; j<M; j++)
            scanf("%d", &cost[c][j]);
    }
    printf("%d\n", dfs(N, M-1));
    tracking(N, M-1);
    puts("");
    return 0;
}