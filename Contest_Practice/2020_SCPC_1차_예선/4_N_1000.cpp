#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=50001;

int T, N, K, M;
char str[MAX_N];
ll arr[MAX_N];

int getMaxNum(int pos) {
    char store = str[pos];
    str[pos] = '1';

    ll tmp = 0;
    ll div = 1;
    for (int i=0; i<K; i++) div *= 10;

    for (int i=0; i<K-1; i++) {
        tmp *= 10;
        tmp += str[i]-'0';
    }

    for (int i=K-1; i<N; i++) {
        tmp *= 10;
        tmp += str[i]-'0';
        tmp %= div;
        arr[i-K+1] = tmp;
    }
    sort(arr,arr+N-K+1);
    arr[N-K+1] = ll(1e12);

    int ret = 0;
    int lo = 0, hi = 0;
    while (1) {
        int diff = arr[hi]-arr[lo];
        ret = max(ret, hi-lo);
        if (diff > M) lo++;
        else if (hi == N-K+1) break;
        else hi++;
    }
    str[pos] = store;
    return ret;
}

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);
        scanf("%d%d%d\n", &N, &K, &M);
        scanf("%s", str);
        if (N <= 1000) {
            int ret = 0;
            for (int i=0; i<=N; i++)
                ret = max(ret, getMaxNum(i));
            printf("%d\n", ret);
        } else {
            printf("%d\n", 0);
        }
    }
    return 0;
}