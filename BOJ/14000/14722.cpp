// baekjoon 14722 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;

int N;
int board[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][3];

int dfs(int x, int y, int state) {
    int &ret = dp[x][y][state];
    if (ret != -1) return ret;

    int tmp = (state == board[x][y] ? 1 : 0);
    ret = tmp;
    // right dir
    if (y != N-1) ret = max(ret, tmp + dfs(x, y+1, (tmp ? (state+1)%3 : state) ));
    // down dir
    if (x != N-1) ret = max(ret, tmp + dfs(x+1, y, (tmp ? (state+1)%3 : state) ));
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            scanf("%d", &board[i][j]);

    printf("%d\n", dfs(0, 0, 0));
    return 0;
}