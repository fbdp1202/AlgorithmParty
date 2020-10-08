// baekjoon 1953 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;

int N, board[MAX_N][MAX_N];
vector<int> team[2];

bool visited[MAX_N];

void dfs(int here, int depth) {
    visited[here] = true;
    team[depth % 2].push_back(here);
    for (int i=1; i<=N; i++) {
        if (!board[here][i] || visited[i]) continue;
        dfs(i, depth+1);
    }
}

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        int C; scanf("%d", &C);
        for (int c=0; c<C; c++) {
            int x; scanf("%d", &x);
            board[i][x] = board[x][i] = 1;
        }
    }

    for (int i=1; i<=N; i++) {
        if (visited[i]) continue;
        dfs(i, 0);
    }
    for (int i=0; i<2; i++) {
        sort(team[i].begin(), team[i].end());
        printf("%d\n", team[i].size());
        for (int nx: team[i])
            printf("%d ", nx);
        puts("");
    }
    return 0;
}