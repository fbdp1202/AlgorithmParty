// baekjoon 2313 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int T, N;
vector<P> seq;

int main() {
    scanf("%d", &T);
    ll ans = 0;
    for (int t=0; t<T; t++) {
        scanf("%d", &N);

        int sum = -1e9, ret = -1e9;
        int l = 0, r = 0;
        int al = 0, ar = 0;
        int x;
        for (int i=0; i<N; i++) {
            scanf("%d", &x);
            if (sum < 0) {
                sum = x;
                l = r = i;
            } else {
                if (sum) r++;
                else l = r = i;
                sum += x;
            }

            if (ret < sum || (ret == sum && r - l < ar - al)) {
                ret = sum;
                al = l, ar = r;
            }
        }
        ans += ret;
        seq.push_back(P(al+1, ar+1));
    }
    printf("%lld\n", ans);
    for (int i=0; i<T; i++)
        printf("%d %d\n", seq[i].first, seq[i].second);
    return 0;
}