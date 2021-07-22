// baekjoon 20056 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<int, P>;
using PPP = pair<P, PP>;

const int dir[8][2] = {
    {-1, 0},
    {-1, 1},
    { 0, 1},
    { 1, 1},
    { 1, 0},
    { 1,-1},
    { 0,-1},
    {-1,-1},
};

const int MAX_N=51;
const int MAX_M=MAX_N*MAX_N;
const int MAX_K=1001;

int N, M, K;
// PPP: (x, y, m, s, d)
vector<PPP> fireball;

/// int : (idx)
queue<int> board[MAX_N][MAX_N];

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

void read_input() {
    N = read_int();
    M = read_int();
    K = read_int();

    for (int i=0; i<M; i++) {
        int x, y, m, s, d;
        x = read_int()-1;
        y = read_int()-1;
        m = read_int();
        s = read_int();
        d = read_int();
        fireball.push_back(PPP(P(x, y), PP(m, P(s, d))));
    }
}

int getMass() {
    int ret = 0;
    for (auto &p : fireball)
        ret += p.second.first;
    return ret;
}

void Move() {
    for (int i=0; i<fireball.size(); i++) {
        if (fireball[i].second.first == 0) continue;

        int x = fireball[i].first.first;
        int y = fireball[i].first.second;
        int s = fireball[i].second.second.first;
        int d = fireball[i].second.second.second;

        int nx = (N * 1000 + x + s * dir[d][0]) % N;
        int ny = (N * 1000 + y + s * dir[d][1]) % N;

        fireball[i].first = P(nx, ny);
        board[nx][ny].push(i);
    }
}

void Split() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int num = board[i][j].size();
            if (num < 2) {
                while (num--) {
                    board[i][j].pop();
                }
                continue;
            }

            int total_mass = 0;
            int total_speed = 0;
            int base_dir = fireball[board[i][j].front()].second.second.second % 2;
            int flag = 0;

            for (int k=0; k<num; k++) {
                int idx = board[i][j].front();
                board[i][j].pop();

                total_mass += fireball[idx].second.first;
                total_speed += fireball[idx].second.second.first;

                fireball[idx].second.first = 0;

                int curr_dir = fireball[idx].second.second.second % 2;
                if (base_dir != curr_dir) flag = 1;
            }

            int n_mass = total_mass / 5;
            int n_speed = total_speed / num;
            if (n_mass == 0) continue;

            for (int k=0; k<8; k+=2)
                fireball.push_back(PPP(P(i, j), PP(n_mass, P(n_speed, k+flag))));
        }
    }
}

int run() {
    for (int i=0; i<K; i++) {
        Move();
        Split();
    }
    return getMass();
}

int main() {
    read_input();

    printf("%d\n", run());

    return 0;
}