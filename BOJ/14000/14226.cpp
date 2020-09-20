// baekjoon 14226 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=2222;
const int MAX_INF=1e9;
int N, dp[MAX_N];

int main() {
    fill(dp, dp+MAX_N, MAX_INF);
    scanf("%d", &N);


    printf("%d\n", dp[N]);
    return 0;
}