#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
vector<int> primes;

void getPrimes(ll x) {
    for (ll i=2; i*i <= x; i++) {
        if (x % i == 0) {
            primes.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1) primes.push_back(x);
}

ll dfs(int here, ll pos, ll num) {
    if (here == primes.size()) return 0;
    ll ret = 0;
    ret += pos*(num/primes[here]);
    ret += dfs(here + 1, pos, num);
    ret += dfs(here + 1, pos*(-1), num/primes[here]);
    return ret;
}

int main() {
    scanf("%d", &N);

    for (int i=1; i<=N; i++) {
        if ((i != 1) && (N/i > i-1)) continue;
        primes.clear();
        getPrimes(i);
        ll ret = i * (i-dfs(0, 1, i));
        printf("%d: %lld\n", i, ret);
        if (ret == N) return !printf("%d\n", i);
    }
    printf("-1\n");
    return 0;
}