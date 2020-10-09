// baekjoon 1800 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<P, int>;

const int MAX_N=1001;
const int MAX_INF=1e9;

int N, M, K;
vector<P> adj[MAX_N];

bool visited[MAX_N][MAX_N];

bool search(int maxValue) {
    memset(visited, 0, sizeof(visited));

    queue<P> q;
    q.push(P(1,K)); // (here, remain_free)
    visited[1][K] = true;

    while (!q.empty()) {
        int curr = q.front().first;
        int freeWire = q.front().second;
        q.pop();
        if (curr == N) return true;
        for (P &p: adj[curr]) {
            int nx = p.first;
            int d = p.second;
            if (d <= maxValue) {
                if (!visited[nx][freeWire]) {
                    visited[nx][freeWire] = true;
                    q.push(P(nx, freeWire));
                }
            } else {
                if (freeWire && !visited[nx][freeWire-1]) {
                    visited[nx][freeWire-1] = true;
                    q.push(P(nx, freeWire-1));
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);

    int lo = 0, hi = 0;
    for (int i=0; i<M; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        adj[x].push_back(P(y, c));
        adj[y].push_back(P(x, c));
        hi = max(hi, c);
    }

    int ret = MAX_INF;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (search(mid)) hi = mid - 1, ret = min(ret, mid);
        else lo = mid + 1;
    }
    printf("%d\n", (ret == MAX_INF) ? -1 : ret);
    return 0;
}