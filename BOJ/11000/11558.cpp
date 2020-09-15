// baekjoon 11558 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=10001;
const int MAX_INF=1e9;

int T, N;
int direct[MAX_N];
bool visited[MAX_N];

int dfs(int here) {
    if (here == N) return 0;

    int ret = MAX_INF;
    visited[here] = true;
    int nx = direct[here];
    if (!visited[nx])
        ret = min(ret, dfs(nx) + 1);

    return ret;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        memset(visited, 0, sizeof(visited));
        for (int i=1; i<=N; i++)
            scanf("%d", &direct[i]);

        int ret = dfs(1);
        if (ret == MAX_INF) ret = 0;
        printf("%d\n", ret);
    }

    return 0;
}