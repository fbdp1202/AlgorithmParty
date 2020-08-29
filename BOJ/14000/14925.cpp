#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1002;

int N, M, board[MAX_N][MAX_N];

int main() {
    memset(board, -1, sizeof(board));
    scanf("%d%d", &N, &M);

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            int x; scanf("%d", &x);
            if (x > 0) board[i][j] = -1;
            else board[i][j] = 1;
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (board[i][j] == -1) continue;
            int tmp = min(min(board[i-1][j-1], board[i-1][j]), board[i][j-1]);
            if (tmp == -1) continue;
            board[i][j] = tmp + 1;
        }
    }

    int ret = 0;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            ret = max(ret, board[i][j]);

    printf("%d\n", ret);
    return 0;
}