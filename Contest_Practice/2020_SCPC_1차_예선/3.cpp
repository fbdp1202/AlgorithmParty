#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;

const int MAX_T=71;
const int MAX_N=1501;
const int MAX_K=2001;
const int MAX_M=100001;

int T, N, K, M;
int dp[MAX_N][MAX_N];
int buf[MAX_N];

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);
        scanf("%d%d%d", &N, &K, &M);
        for (int i=1; i<=N; i++)
            fill(dp[i], dp[i]+MAX_N, 1e9);

        for (int i=1; i<=N; i++)
            buf[i]=i, dp[i][i]=0;

        for (int i=0; i<K; i++) {
            int s, e;
            scanf("%d%d", &s, &e);
            swap(buf[s], buf[e]);
            s = buf[s], e = buf[e];
            dp[s][e] = 1;
            for (int j=1; j<=N; j++) {
                dp[s][j] = min(dp[s][j], dp[s][e] + dp[j][e]);
                dp[e][j] = min(dp[e][j], dp[s][j] + dp[s][e]);
            }
        }
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (dp[i][j]==1e9) printf("x ");
                else printf("%d ", dp[i][j]);
            }
            puts("");
        }
        puts("");
        int ret = 0;
        for (int i=0; i<M; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            int v = dp[buf[b]][a];
            // printf("%d %d: %d\n", a, buf[b], v);
            ret += (v == 1e9 ? -1 : v);
        }
        printf("%d\n", ret);
    }
    return 0;
}