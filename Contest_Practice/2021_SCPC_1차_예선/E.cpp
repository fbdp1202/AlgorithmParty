#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int MAX_N=100001;
const int MAX_K=200001;
const int MAX_INF=2e9;

int T, N, K;

int p[MAX_N];
bool cf[MAX_N];
vector<vector<P>> adj;

int dist[MAX_N];
int command[MAX_K][4];

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int find(int n) {
    if (p[n] < 0) return n;
    p[n] = find(p[n]);
    cf[n] |= cf[p[n]];
    cf[p[n]] |= cf[n];
    return p[n];
}

int find2(int n) {
    if (p[n] < 0) return n;
    p[n] = find2(p[n]);
    return p[n];
}

int connect(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) return -1;
    if (cf[a]) return 1;
    if (a == b) return 0;
    return -1;
}

int connect2(int a, int b) {
    a = find2(a);
    b = find2(b);
    if (a != b) return -1;
    return 0;
}

void DFS(int curr, int sum, int pv) {
    dist[curr] = sum;
    for (auto &p : adj[curr]) {
        int nx = p.first;
        int w = p.second;
        if (nx == pv) continue;
        DFS(nx, sum + w, curr);
    }
}

void update(int curr, int sum) {
    DFS(curr, sum, -1);
}

void merge(int x, int y, int d) {
    int a = find(x);
    int b = find(y);
    if (a == b) return;
    if (a > b) {
        swap(a, b);
        swap(x, y);
        d = -d;
    }
    cf[a] |= cf[b];
    cf[b] |= cf[a];
    if (!cf[a]) {
        update(y, dist[x]+d);
    }
    p[b] = a;
}

void merge2(int a, int b) {
    a = find2(a);
    b = find2(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    p[b] = a;
}

int main () {
    setbuf(stdout, NULL);

    T = read_int();
    for (int t=1; t<=T; t++) {
        fill(p, p+MAX_N, -1);

        printf("Case #%d\n", t);
        N = read_int();
        K = read_int();

        bool flag = true;
        for (int i=0; i<K; i++) {
            int C = read_int();
            command[i][0] = C;
            if (C == 1) {
                int a, b, d;
                scanf("%d%d%d", &a, &b, &d);
                command[i][1] = a - 1;
                command[i][2] = b - 1;
                command[i][3] = d;
                if (d) flag = false;
            } else {
                int a, b;
                scanf("%d%d", &a, &b);
                command[i][1] = a - 1;
                command[i][2] = b - 1;
            }
        }

        if (flag) {
            for (int i=0; i<K; i++) {
                int C = command[i][0];
                if (C == 1) {
                    int a, b, d;
                    a = command[i][1];
                    b = command[i][2];
                    if (a > b) {
                        swap(a, b);
                    }

                    int ret = connect2(a, b);

                    if (ret == -1) {
                        merge2(a, b);
                    }
                } else {
                    int a, b, d;
                    a = command[i][1];
                    b = command[i][2];
                    if (a > b) swap(a, b);

                    int ret = connect2(a, b);
                    if (ret == -1) puts("NC");
                    else printf("%d\n", 0);
                }
            }
            continue;
        }

        memset(dist, 0, sizeof(dist));
        memset(cf, 0, sizeof(cf));

        adj = vector<vector<P>>(N);

        for (int i=0; i<K; i++) {
            int C = command[i][0];
            if (C == 1) {
                int a, b, d;
                a = command[i][1];
                b = command[i][2];
                d = command[i][3];
                if (a > b) {
                    swap(a,b);
                    d = -d;
                }
                int ret = connect(a, b);

                if (ret == -1) {
                    merge(a, b, d);
                    adj[a].push_back(P(b, d));
                    adj[b].push_back(P(a, -d));
                }
                if (ret == 0) {
                    if (dist[b] - dist[a] != d) cf[find(a)] = true;
                }
            } else {
                int a, b, d;
                a = command[i][1];
                b = command[i][2];
                d = 1;
                if (a > b) {
                    swap(a, b);
                    d = -1;
                }
                int ret = connect(a, b);
                if (ret == -1) puts("NC");
                else if (ret == 1) puts("CF");
                else {
                    printf("%d\n", (dist[b] - dist[a]) * d);
                }
            }
        }
    }
    return 0;
}