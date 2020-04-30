#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=10001;

int N, x[MAX_N];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &x[i]);
    sort(x, x+N);
    ll sum = 0, ret = 0;
    for (int i=1; i<N; i++) {
        sum += 1LL * (x[i] - x[i-1]) * i;
        ret += sum * 2;
    }
    printf("%lld\n", ret);
    return 0;
}