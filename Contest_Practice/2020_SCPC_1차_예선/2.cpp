#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=3001;

int T, N, K;
int A[MAX_N], B[MAX_N];
int dp[MAX_N][MAX_N];
int ans;

int dfs(int x, int y) {
    printf("dfs(%d, %d)\n", x, y);
    int &ret = dp[x][y];
    if (ret != -1) return ret;

    ret = 0;
    // X 선택
    int sum = 0;
    for (int i=x; i>=1; i--) {
        sum += A[i];
        if (sum > K) break;
        ret |= (!dfs(i-1,y));
    }
    // Y 선택
    sum = 0;
    for (int i=y; i>=1; i--) {
        sum += B[i];
        if (sum > K) break;
        ret |= (!dfs(x,i-1));
    }
    ans += ret;
    return ret;
}

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

        ans = 1;
        dfs(N, N);

        for (int i=0; i<=N; i++) {
            for (int j=0; j<=N; j++) {
                printf("%d ", dp[i][j]);
            }
            puts("");
        }

        printf("%d %d\n", ans, (N+1)*(N+1)-ans);
    }
    return 0;
}