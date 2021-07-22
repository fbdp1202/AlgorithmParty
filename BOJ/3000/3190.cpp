#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pic = pair<int, char>;
using P = pair<int, int>;

const int MAX_N = 101;
const int MAX_K = 101;
const int MAX_L = 101;

const int dir[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

int N, K, L;
int board[MAX_N][MAX_N];
Pic game[MAX_L];

void read_input() {
    scanf("%d%d", &N, &K);
    for (int i=0; i<K; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        board[y-1][x-1] = 1;
    }

    scanf("%d", &L);
    int px = 0;
    for (int i=0; i<L; i++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        game[i] = Pic(x - px, c);
        px = x;
    }
}

int run() {
    deque<P> dq;
    board[0][0] = 2;
    dq.push_front(P(0,0));

    int cur_dir = 0;
    int result = 0;

    for (int i=0; i<L; i++) {
        int dist = game[i].first;
        int t = ((game[i].second == 'D') ? 1 : -1);
        int nx_dir = (4 + cur_dir + t) % 4;

        for (int j=0; j < dist; j++) {
            result++;
            int cx = dq.front().first;
            int cy = dq.front().second;
            int nx = cx + dir[cur_dir][0];
            int ny = cy + dir[cur_dir][1];
            // clip on board
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) return result;
            if (board[nx][ny] == 2) return result;

            if (board[nx][ny] == 0) {
                int px = dq.back().first;
                int py = dq.back().second;
                board[px][py] = 0;
                dq.pop_back();
            }
            board[nx][ny] = 2;
            dq.push_front(P(nx, ny));
        }
        cur_dir = nx_dir;
    }
    for (int j=0; ; j++) {
        result++;
        int cx = dq.front().first;
        int cy = dq.front().second;
        int nx = cx + dir[cur_dir][0];
        int ny = cy + dir[cur_dir][1];
        // clip on board
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) return result;
        if (board[nx][ny] == 2) return result;

        if (board[nx][ny] == 0) {
            int px = dq.back().first;
            int py = dq.back().second;
            board[px][py] = 0;
            dq.pop_back();
        }
        board[nx][ny] = 2;
        dq.push_front(P(nx, ny));
    }
    return -1;
}


int main() {
    read_input();
    printf("%d\n", run());
    return 0;
}