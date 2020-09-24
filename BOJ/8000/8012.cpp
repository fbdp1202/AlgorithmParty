// baekjoon 8012 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=30001;
const int MAX_M=5001;
const int MAX_D=16;

int N, M;
int parent[MAX_N][MAX_D];
int depth[MAX_N];
vector<int> adj[MAX_N];

void makeTreeByDFS(int curr) {
    for (int next: adj[curr]) {
        if (depth[next] == -1) {
            parent[next][0] = curr;
            depth[next] = depth[curr] + 1;
            makeTreeByDFS(next);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N-1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(parent, -1, sizeof(parent));
    fill(depth, depth+N, -1);
    depth[0] = 0;

    makeTreeByDFS(0);

    for (int j=0; j<MAX_D; j++)
        for (int i=1; i<N; i++)
            if (parent[i][j] != -1)
                parent[i][j+1] = parent[parent[i][j]][j];

    scanf("%d", &M);

    int ret = 0;
    int x, y;
    scanf("%d", &x); x--;
    for (int i=0; i<M-1; i++) {
        scanf("%d", &y); y--;
        int u, v;
        u = x; v = y;

        int dist = 0;
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        dist += diff;

        for (int j=0; diff; j++) {
            if (diff % 2) u = parent[u][j];
            diff /= 2;
        }

        if (u != v) {
            for (int j=MAX_D-1; j>=0; j--) {
                if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
                    u = parent[u][j];
                    v = parent[v][j];
                    dist += (1<<j)*2;
                }
            }
            dist += 2;
            u = parent[u][0];
        }
        ret += dist;
        x = y;
    }
    printf("%d\n", ret);

    return 0;
}