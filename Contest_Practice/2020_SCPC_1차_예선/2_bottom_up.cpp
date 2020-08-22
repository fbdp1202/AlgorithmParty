#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=3001;

int T, N, K;
int A[MAX_N], B[MAX_N];
int Anum[MAX_N], Bnum[MAX_N];
int dp[MAX_N][MAX_N];

int getDP(int x, int y) {
    if (x < 0 || y < 0) return 0;
    return dp[x][y];
}

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);

        scanf("%d%d", &N, &K);
        for (int i=1; i<=N; i++) {
            scanf("%d", &A[i]);
            A[i] = A[i] + A[i-1];
        }

        int lo = 0, hi = 1;
        memset(Anum, 0, sizeof(Anum));
        while (1) {
            if (A[hi]-A[lo] > K) lo++;
            else if (hi > N) break;
            else {
                Anum[hi] = max(Anum[hi], hi-lo);
                hi++;
            }
        }

        for (int i=1; i<=N; i++) {
            scanf("%d", &B[i]);
            B[i] = B[i] + B[i-1];
        }

        memset(Bnum, 0, sizeof(Bnum));
        lo = 0, hi = 1;
        while (1) {
            if (B[hi]-B[lo] > K) lo++;
            else if (hi > N) break;
            else {
                Bnum[hi] = max(Bnum[hi], hi-lo);
                hi++;
            }
        }


        for (int i=0; i<=N; i++) {
            for (int j=0; j<=N; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = 1;
                    continue;
                }
                int tmp = Bnum[i] - (getDP(i-1, j) - getDP(i-1, j-1) - getDP(i-1-Bnum[i],j) + getDP(i-1-Bnum[i],j-1));
                tmp += Anum[j] - (getDP(i, j-1) - getDP(i-1, j-1) - getDP(i, j-1-Anum[j]) + getDP(i-1,j-1-Anum[j]));
                // printf("%d ", tmp);
                dp[i][j] = getDP(i, j-1) + getDP(i-1, j) - getDP(i-1, j-1) + (tmp > 0 ? 1 : 0);
            }
        }
        printf("%d %d\n", dp[N][N], (N+1)*(N+1)-dp[N][N]);
    }
    return 0;
}