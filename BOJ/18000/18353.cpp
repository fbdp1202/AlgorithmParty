// baekjoon 18353 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=2001;

int N, dp[MAX_N], a[MAX_N];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &a[i]);

    int ret = 0;
    for (int i=0; i<N; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (a[j] > a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ret = max(ret, dp[i]);
    }
    printf("%d\n", N-ret);
    return 0;
}