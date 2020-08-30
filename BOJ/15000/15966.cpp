// baekjoon 15966 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100001;
const int MAX_V=1000001;

int N, dp[MAX_V];
int x, ret;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &x);
        dp[x] = max(dp[x], dp[x-1] + 1);
        ret = max(ret, dp[x]);
    }
    printf("%d\n", ret);
    return 0;
}