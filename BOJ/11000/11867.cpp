// baekjoon 11867 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;

int N;
int dp[MAX_N][MAX_N];

int dfs(int A, int B) {
    // win condition
    if (A == 2 || B == 2)
        return 1;

    int &ret = dp[A][B];
    if (ret != -1) return ret;

    ret = 0;
    // Choose first Box
    for (int i=1; i<A; i++)
        ret |= !(dfs(i, A-i));
    // Choose Second Box
    for (int i=1; i<B; i++)
        ret |= !(dfs(i, B-i));

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int A, B;
    scanf("%d%d", &A, &B);
    int ret = dfs(A, B);
    puts(ret == 1 ? "A":"B");
    return 0;
}