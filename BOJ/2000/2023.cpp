// baekjoon 2023 yechan
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

bool isprime(ll x) {
    if (x < 2) return false;
    for (ll div=2; div*div<=x; div++)
        if (x % div == 0)
            return false;
    return true;
}

void tracking(int pos, ll here) {
    if (pos == N) {
        printf("%lld\n", here);
    } else {
        for (int i=1; i<=9; i++) {
            ll next = here*10 + i;
            if (isprime(next)) tracking(pos+1, next);
        }
    }
}

int main() {
    scanf("%d", &N);
    tracking(0,0);
    return 0;
}