// basekjoon 19238 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using PP = pair<P, P>;

const int MAX_N=21;
const int MAX_M=MAX_N*MAX_N;
const int MAX_INF=1e9;

const int dir[4][2] = {
    { 0, -1},
    {-1,  0},
    { 0,  1},
    { 1,  0},
};

int N, M, K;
int board[MAX_N][MAX_N];
int cx, cy;

PP people[MAX_M];

int pos[MAX_N][MAX_N];
bool finish[MAX_M];
bool visited[MAX_N][MAX_N];

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

void read_input() {
    N = read_int();
    M = read_int();
    K = read_int();

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            board[i][j] = read_int();
            pos[i][j] = -1;
        }
    }

    cx = read_int() - 1;
    cy = read_int() - 1;

    for (int i=0; i<M; i++) {
        int sx = read_int() - 1;
        int sy = read_int() - 1;
        int ex = read_int() - 1;
        int ey = read_int() - 1;
        people[i] = PP(P(sx, sy), P(ex, ey));
    }

    sort(people, people + M);

    for (int i=0; i<M; i++) {
        int sx = people[i].first.first;
        int sy = people[i].first.second;
        pos[sx][sy] = i;
    }
}

P closest(int sx, int sy) {
    memset(visited, 0, sizeof(visited));
    queue<P> q;
    q.push(P(sx, sy));
    visited[sx][sy] = true;

    int dist = 0;
    while (!q.empty()) {
        int qSize = q.size();
        int dest = MAX_INF;

        while (qSize--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (pos[x][y] != -1)
                dest = min(dest, pos[x][y]);

            for (int d=0; d<4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (visited[nx][ny]) continue;
                if (board[nx][ny]) continue;

                visited[nx][ny] = true;
                q.push(P(nx, ny));
            }
        }

        if (dest != MAX_INF) {
            int x = people[dest].first.first;
            int y = people[dest].first.second;
            pos[x][y] = -1;
            return P(dest, dist);
        }

        dist++;
    }

    return P(-1, MAX_INF);
}

int move(int idx) {
    memset(visited, 0, sizeof(visited));
    int sx = people[idx].first.first;
    int sy = people[idx].first.second;
    int ex = people[idx].second.first;
    int ey = people[idx].second.second;

    queue<P> q;
    q.push(P(sx, sy));

    int cost = 0;
    while (!q.empty()) {
        int qSize = q.size();
        while (qSize--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == ex && y == ey) return cost;

            for (int d=0; d<4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (visited[nx][ny]) continue;
                if (board[nx][ny]) continue;

                visited[nx][ny] = true;
                q.push(P(nx, ny));
            }
        }
        cost++;
        if (cost > K) return -1;
    }
    return -1;
}

int run() {
    int sx = cx, sy = cy;

    for (int i=0; i<M; i++) {
        P p = closest(sx, sy);
        int idx = p.first;
        int dist = p.second;

        int ssx = people[idx].first.first;
        int ssy = people[idx].first.second;
        int ex = people[idx].second.first;
        int ey = people[idx].second.second;


        if (idx == -1) return -1;
        if (dist > K) return -1;

        K -= dist;

        int cost =  move(idx);
        if (cost == -1) return -1;

        K += cost;
        sx = people[idx].second.first;
        sy = people[idx].second.second;
    }
    return K;
}

int main() {

    read_input();

    printf("%d\n", run());
    return 0;
}