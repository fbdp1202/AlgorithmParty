// baekjoon 13702 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=10001;
const ll MAX_INF=(1LL<<60);

int N, K;
ll arr[MAX_N];

bool search(ll spoon) {
    ll count = 0;
    for (int i=0; i<N; i++) {
        count += arr[i] / spoon;
        if (count >= K) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &N, &K);
    ll lo = 1, hi = 0;
    for (int i=0; i<N; i++) {
        scanf("%lld", &arr[i]);
        hi = max(hi, arr[i]);
    }

    ll ret = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (search(mid)) {
            ret = max(ret, mid);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("%lld\n", ret);
    return 0;
}