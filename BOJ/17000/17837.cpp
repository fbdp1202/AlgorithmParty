// basekjoon 17837 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<P, P>;

const int MAX_N=13;
const int MAX_K=11;

const int dir[4][2] = {
    {-1, 0},
    { 0, 1},
    { 1, 0},
    { 0,-1}
};
int decoder[5] = {0, 1, 3, 0, 2};

int N, K;
int board[MAX_N][MAX_N];
PP hourse[MAX_K];
int state[MAX_N][MAX_N];

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

void read_input() {
    N = read_int();
    K = read_int();
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            board[i][j] = read_int();

    for (int i=0; i<K; i++) {
        int x = read_int() - 1;
        int y = read_int() - 1;
        int d = read_int();
        hourse[i] = PP(P(x, y), P(decoder[d], 0));
        state[x][y] += 1;
    }
}

bool check_done() {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (state[i][j] >= 4)
                return true;
    return false;
}

int run() {
    int ret = 1;

    while (1) {
        for (int i=0; i<K; i++) {
            int x = hourse[i].first.first;
            int y = hourse[i].first.second;
            int d = hourse[i].second.first;
            int h = hourse[i].second.second;

            int s = state[x][y] - h;

            vector<PP> v(s);
            vector<int> idx(s);
            idx[0] = i;

            v[0] = PP(P(x, y), P(d, h));

            for (int j=0; j<K; j++) {
                if (i == j) continue;

                int nx = hourse[j].first.first;
                int ny = hourse[j].first.second;
                int nd = hourse[j].second.first;
                int nh = hourse[j].second.second;
                if (x != nx || y != ny) continue;

                if (nh < h) continue;

                int nidx = nh - h;
                v[nidx] = PP(P(nx, ny), P(nd, nh));
                idx[nidx] = j;
            }

            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            int nd = d;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                nd = (d + 2) % 4;
                nx = x + dir[nd][0];
                ny = y + dir[nd][1];
                if (board[nx][ny] == 2) {
                    hourse[i].second.first = nd;
                    continue;
                }
            }

            if (board[nx][ny] == 2) {
                nd = (d + 2) % 4;
                nx = x + dir[nd][0];
                ny = y + dir[nd][1];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                    hourse[i].second.first = nd;
                    continue;
                }
                if (board[nx][ny] == 2) {
                    hourse[i].second.first = nd;
                    continue;
                }
            }

            int nh = state[nx][ny];
            if (board[nx][ny] == 0) {
                hourse[idx[0]] = PP(P(nx, ny), P(nd, nh));
                for (int j=1; j<s; j++) {
                    hourse[idx[j]] = PP(P(nx, ny), P(v[j].second.first, nh+j));
                }
                state[x][y] -= s;
                state[nx][ny] += s;
            }

            if (board[nx][ny] == 1) {
                hourse[idx[0]] = PP(P(nx, ny), P(nd, nh + s - 1));
                for (int j=1; j<s; j++) {
                    hourse[idx[j]] = PP(P(nx, ny), P(v[j].second.first, nh + s - 1 - j));
                }
                state[x][y] -= s;
                state[nx][ny] += s;
            }

            if (check_done()) return ret;
        }

        ret++;
        if (ret > 1000) return -1;
    }
    return ret;
}

int main() {
    read_input();

    printf("%d\n", run());
    return 0;
}