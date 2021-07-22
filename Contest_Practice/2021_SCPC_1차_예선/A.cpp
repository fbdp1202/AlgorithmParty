#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100001;

int T, N;
int D[MAX_N];

int p[MAX_N];

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int find(int n) {
    if (p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}

int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    p[b] = a;
    return 1;
}

int run() {
    int ret = N;
    for (int i=0; i<N; i++) {
        int a = i, b = i + D[i];
        if (b >= N) continue;
        ret -= merge(a, b);
    }
    return ret;
}

int main () {
    setbuf(stdout, NULL);

    T = read_int();
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);
        memset(D, 0, sizeof(D));
        fill(p, p+MAX_N, -1);
        N = read_int();
        for (int i=0; i<N; i++) {
            D[i] = read_int();
        }
        printf("%d\n", run());
    }
    return 0;
}