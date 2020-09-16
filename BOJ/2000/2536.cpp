// baekjoon 2536 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<P,P>;

const int MAX_N=100001;
const int MAX_K=5002;
const int MAX_INF=1e9;

int N, M, K;
vector<int> adj[MAX_K];
PP component[MAX_K];

int dist[MAX_K];
bool visited[MAX_K];

bool cross(int a, int b) {
    int ax1 = component[a].first.first;
    int ay1 = component[a].first.second;
    int ax2 = component[a].second.first;
    int ay2 = component[a].second.second;

    int bx1 = component[b].first.first;
    int by1 = component[b].first.second;
    int bx2 = component[b].second.first;
    int by2 = component[b].second.second;

    // is overlap x cordinate
    if ( (ax1 <= bx1 && bx1 <= ax2) || (ax1 <= bx2 && bx2 <= ax2) ||
         (bx1 <= ax1 && ax1 <= bx2) || (bx1 <= ax2 && ax2 <= bx2) ) {
        // is overlap y cordinate
        if ( (ay1 <= by1 && by1 <= ay2) || (ay1 <= by2 && by2 <= ay2) ||
             (by1 <= ay1 && ay1 <= by2) || (by1 <= ay2 && ay2 <= by2) ) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i=1; i<=K; i++) {
        int num, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &num, &x1, &y1, &x2, &y2);
        component[num] = PP(P(min(x1,x2),min(y1,y2)),P(max(x1,x2),max(y1,y2)));
    }
    int sx, sy, dx, dy;
    scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
    component[0] = PP(P(sx,sy),P(sx,sy));
    component[K+1] = PP(P(dx,dy),P(dx,dy));
    for (int i=0; i<=K+1; i++) {
        for (int j=i+1; j<=K+1; j++) {
            if (cross(i, j)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    fill(dist, dist+MAX_K, MAX_INF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P> > PQ;
    PQ.push(P(0, 0));
    while (!PQ.empty()) {
        int curr;
        do {
            curr = PQ.top().second;
            PQ.pop();
        } while (!PQ.empty() && visited[curr]);
        if (visited[curr]) break;

        visited[curr] = true;
        for (int nx: adj[curr]){
            if (dist[nx] > dist[curr] + 1) {
                dist[nx] = dist[curr] + 1;
                PQ.push(P(dist[nx], nx));
            }
        }
    }
    printf("%d\n", dist[K+1]-1);
    return 0;
}