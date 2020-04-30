// baekjoon 2632 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_V=2000001;
const int MAX_N=1001;

int T, N, M;
int A[MAX_N], B[MAX_N];
int dpA[MAX_V], dpB[MAX_V];

void findCase(int *input, int *dp, int num) {
    int totalSum = 0;
    for (int start=0; start<num; start++) {
        totalSum += input[start];
        int sum = input[start];
        dp[sum]++;
        for (int next=(start+1)%num; next != start; next=(next+1)%num) {
            sum += input[next];
            dp[sum]++;
        }
    }
    dp[0] = dp[totalSum] = 1;
}

int main() {
    scanf("%d", &T);
    scanf("%d%d", &N, &M);
    int sumA = 0, sumB = 0;
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    for (int i=0; i<M; i++) scanf("%d", &B[i]);
    findCase(A, dpA, N);
    findCase(B, dpB, M);

    ll ret = 0;
    for (int i=0; i<=T; i++)
        ret += dpA[i] * dpB[T-i];
    printf("%lld\n", ret);
    return 0;
}