#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX_N = 20001;
const int MAX_M = 50001;

int T, N, M;

int read_int() {
    int x;
    scanf(" %d", &x);
    return x;
}

int main () {
    setbuf(stdout, NULL);

    T = read_int();
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);

        N = read_int();
        M = read_int();

        ll ret = (1LL << 62);
        ll ret1 = 0;
        ll ret2 = 0;

        int n_odd = 0;
        vector<P> gain;
        for (int i=0; i<N; i++) {
            int C = read_int();
            if (C % 2 == 1) n_odd++;

            vector<int> v;
            for (int j=0; j<C; j++) {
                int x;
                scanf("%d", &x);
                v.push_back(x);
            }
            sort(v.begin(), v.end());

            if (C % 2 == 1) {
                ret1 += 2 * v[0] + v[1] + v[2] + v[3];          // [2, 1, 1, 1]
                ret2 += 2 * v[0] + v[1];                        // [2, 1, 0, 0]
            } else {
                ret1 += v[0] + v[1] + v[2] + v[3];              // [1, 1, 1, 1]
                ret2 += 2 * v[0] + 2 * v[1] + v[2] + v[3];      // [2, 2, 1, 1]
            }
            int mode = (C % 2 == 1) ? 1 : 2;
            gain.push_back(P(v[2]+v[3], mode));
        }
        sort(gain.begin(), gain.end());

        if (n_odd == 2 && gain[N-1].second == 1 && gain[N-2].second == 1) {
            if (gain.size() >= 3) {
                ll loss = gain[N-3].first + gain[N-1].first;
                ret = min(ret, ret1 - loss);
            }
            ret = min(ret, ret2);
        } else {
            ll loss = gain[N-1].first + gain[N-2].first;
            ret = min(ret, ret1 - loss);
        }
        printf("%lld\n", ret);
    }
    return 0;
}