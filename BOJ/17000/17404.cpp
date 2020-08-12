#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;
const int MAX_INF=1e9;
int N;
int dp[MAX_N][3][3]; // [current house][start color][prev_color]
int board[MAX_N][3];

int dfs(int here, int start, int state) {
    int &ret = dp[here][start][state];
    if (ret != -1) return ret;

    ret = MAX_INF;
    if (here == N-1) {
        for (int i=0; i<3; i++) {
            if (start == i || state == i) continue;
            ret = min(ret, board[here][i]);
        }
        return ret;
    }

    for (int i=0; i<3; i++) {
        if (state == i) continue;
        ret = min(ret, dfs(here+1, start, i) + board[here][i]);
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    scanf("%d", &N);
    for (int i=0; i<N; i++)
        for (int j=0; j<3; j++)
            scanf("%d", &board[i][j]);

    int result = MAX_INF;
    for (int s=0; s<3; s++)
        result = min(result, dfs(1, s, s) + board[0][s]);
    printf("%d\n", result);
    return 0;
}