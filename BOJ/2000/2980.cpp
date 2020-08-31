// baekjoon 2980 yechan
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=101;

int N, L;

int wait_light(int t, int r, int g) {
    t %= (r+g);
    if (t < r) return r-t;
    return 0;
}

int main() {
    scanf("%d%d", &N, &L);
    int cur_time=0, cur_pos = 0;
    for (int i=0; i<N; i++) {
        int D, R, G;
        scanf("%d%d%d", &D, &R, &G);
        // move pos(D)
        cur_time += (D - cur_pos);
        cur_pos = D;

        // wait light
        cur_time += wait_light(cur_time, R, G);
    }
    if (cur_pos < L) cur_time += L - cur_pos;
    printf("%d\n", cur_time);
    return 0;
}