// baekjoon 14699 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=5001;
const int MAX_M=100001;

int N, M;
int h[MAX_N];
vector<int> adj[MAX_N];
int dp[MAX_N];

int dfs(int here) {
    int &ret = dp[here];
    if (ret != 0) return ret;
    ret = 1;
    for (int nx: adj[here])
        ret = max(ret, 1 + dfs(nx));
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; i++) {
        scanf("%d", &h[i]);
    }

    for (int i=0; i<M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (h[u] < h[v]) adj[u].push_back(v);
        else adj[v].push_back(u);
    }

    for (int i=1; i<=N; i++)
        printf("%d\n", dfs(i));
    return 0;
}
