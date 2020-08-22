#include <bits/stdc++.h>
using namespace std;

const int MAX_N=200001;

int T, N, K;
int A[MAX_N], B[MAX_N];

int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);

        scanf("%d%d", &N, &K);
        for (int i=0; i<N; i++)
            scanf("%d", &A[i]);
        for (int i=0; i<N; i++)
            scanf("%d", &B[i]);

        sort(A, A+N);
        sort(B, B+N);
        int ret = 0;
        for (int i=0; i<K; i++)
            ret = max(ret, A[i] + B[K-1-i]);
        printf("%d\n", ret);
    }
    return 0;
}