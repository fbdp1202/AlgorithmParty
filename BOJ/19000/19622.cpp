// baekjoon 19622 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<P, int>;

const int MAX_N=100001;

int N;
int dp[MAX_N][2];

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + c;
    }
    printf("%d\n", max(dp[N][0], dp[N][1]));
    return 0;
}