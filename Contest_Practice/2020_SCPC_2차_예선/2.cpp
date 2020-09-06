#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=300001;

int T, N;
ll A[MAX_N], M;

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);
        scanf("%d%lld", &N, &M);
        for (int i=0; i<N; i++)
            scanf("%lld", &A[i]);

        set<ll> s;
        s.insert(0);
        ll ret = 0, tmp = 0;
        for (int i=0; i<N; i++) {
            ll ans = 0;
            tmp += A[i];
            ans = *s.lower_bound(tmp-M);
            s.insert(tmp);
            if (tmp - ans <= M) ret = max(ret, tmp - ans);
        }
        printf("%lld\n", ret);
    }
    return 0;
}