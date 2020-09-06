#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=200001;
const ll MAX_INF=(1LL<<62);
const ll INIT_CON=-4557430888798830400LL;

int T, N;
int A[MAX_N], B[MAX_N];
ll dp[MAX_N][2][2];

ll dfs(int here, int up, int down) {
    if (here + up == N || here + down == N) return 0;
    ll &ret = dp[here][up][down];
    if (ret != INIT_CON) return ret;
    ret = MAX_INF;
    if (up == 0) ret = min(ret, dfs(here, 1, down));
    if (down == 0) ret = min(ret, dfs(here, up, 1));
    ret = min(ret, dfs(here+1, up, down) + abs(A[here+up]-B[here+down]));
    return ret;
}

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);
        memset(dp, 0xc0c0, sizeof(dp));
        scanf("%d", &N);
        for (int i=0; i<N; i++)
            scanf("%d", &A[i]);
        for (int i=0; i<N; i++)
            scanf("%d", &B[i]);

        sort(A, A+N);
        sort(B, B+N);
        printf("%lld\n", dfs(0,0,0));
    }
    return 0;
}