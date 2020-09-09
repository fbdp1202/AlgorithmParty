// baekjoon 4811 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=31;

int N;
ll dp[MAX_N][MAX_N];

ll dfs(int lt, int rt) {
    ll &ret = dp[lt][rt];
    if (ret != -1) return ret;

    ret = 0;
    // divide one, and eat
    if (lt > 0) ret += dfs(lt-1, rt+1);

    // just eat
    if (rt > 0) ret += dfs(lt, rt-1);

    return ret;
}

int main() {
    for (int i=0; i<MAX_N; i++)
        fill(dp[i], dp[i]+MAX_N, -1);
    dp[0][0]=1;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        printf("%lld\n", dfs(N,0));
    }
    return 0;
}