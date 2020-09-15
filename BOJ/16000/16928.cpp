// baekjoon 16928 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=15;
const int MAX_W=101;
const int MAX_INF=1e9;

int N, M;
int direct[MAX_W];
bool visited[MAX_W];

int bfs(int here) {
    queue<int> q;
    q.push(here);
    visited[here] = true;

    int ret = 0;
    while (!q.empty()) {
        int qSize = q.size();
        for (int qs=0; qs<qSize; qs++) {
            int curr = q.front();
            q.pop();
            if (curr == 100) return ret;

            for (int i=1; i<=6; i++) {
                int nx = direct[curr + i];
                if (!visited[nx]) {
                    visited[nx] = true;
                    q.push(nx);
                }
            }
        }
        ret++;
    }
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=1; i<=100; i++) {
        direct[i] = i;
    }

    for (int i=0; i<N; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        direct[u] = v;
    }
    for (int i=0; i<M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        direct[u] = v;
    }

    printf("%d\n", bfs(1));
    return 0;
}