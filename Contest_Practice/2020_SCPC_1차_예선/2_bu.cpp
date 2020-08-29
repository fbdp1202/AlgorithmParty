#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=3001;

int T, N, K;
int A[MAX_N], B[MAX_N];
int dp[MAX_N][MAX_N];
int ret;

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 1;
        printf("Case #%d\n", t);

        scanf("%d%d", &N, &K);
        for (int i=1; i<=N; i++)
            scanf("%d", &A[i]);
        for (int i=1; i<=N; i++)
            scanf("%d", &B[i]);

        ret = 0;
        for (int i=0; i<=N; i++) {
            for (int j=0; j<=N; j++) {

            }
        }
        printf("%d %d\n", ret, (N+1)*(N+1)-ret);
    }
    return 0;
}