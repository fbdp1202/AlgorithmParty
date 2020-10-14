#include <bits/stdc++.h>
using namespace std;
const int MAX_N=101;

int N, L, K;

int main() {
    scanf("%d%d%d", &N, &L, &K);

    int ret = 0, count = 0;
    for (int i=0; i<N; i++) {
        int x, y; scanf("%d%d", &x, &y);
        if (K > 0 && y <= L) K--, ret += 140;
        else if (x <= L) count++;
    }
    ret += min(K, count)*100;
    printf("%d\n", ret);
    return 0;
}
