// backjoon 14499 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 21;
const int MAX_K = 1001;
const int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int N, M, sx, sy, K;
int board[MAX_N][MAX_N];
int command[MAX_K];
int decoder[5] = {0, 1, 3, 0, 2};
int bias[4] = {0, 1, 0 -1};

struct Dice{
    int id;
    int value;
    Dice *pos[5];
    Dice(): Dice(0, -1){}
    Dice(int v, int id): value(v), id(id) {
        for (int d=0; d<4; d++) pos[d] = nullptr;
    }

    void init_pos(
        Dice *up,
        Dice *right,
        Dice *bottom,
        Dice *left,
        Dice *dic
        ) {
        pos[0] = up;
        pos[1] = right;
        pos[2] = bottom;
        pos[3] = left;
        pos[4] = dic;
    }

    Dice* move(int d) {
        return pos[d];
    }

    void set_value(int v) {
        value = v;
    }

    int front() {
        return pos[4]->value;
    }
};
Dice dice[7];

void make_dice() {
    for (int i=1; i<=6; i++) dice[i].id = i;

    dice[1].init_pos(
        &dice[2],
        &dice[3],
        &dice[5],
        &dice[4],
        &dice[6]
    );

    dice[2].init_pos(
        &dice[6],
        &dice[3],
        &dice[1],
        &dice[4],
        &dice[5]
    );

    dice[3].init_pos(
        &dice[2],
        &dice[6],
        &dice[5],
        &dice[1],
        &dice[4]
    );

    dice[4].init_pos(
        &dice[2],
        &dice[1],
        &dice[5],
        &dice[6],
        &dice[3]
    );

    dice[5].init_pos(
        &dice[1],
        &dice[3],
        &dice[6],
        &dice[4],
        &dice[2]
    );

    dice[6].init_pos(
        &dice[5],
        &dice[3],
        &dice[2],
        &dice[4],
        &dice[1]
    );
}

void read_input() {
    scanf("%d%d", &N, &M);
    scanf("%d%d", &sx, &sy);
    scanf("%d", &K);
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%d", &board[i][j]);
    for (int i=0; i<K; i++)
        scanf("%d", &command[i]);
}

void run() {
    int x = sx, y = sy;
    Dice *curr = &dice[6];
    int b = 0;
    for (int i=0; i<K; i++) {
        int p = decoder[command[i]];
        int nx = x + dir[p][0];
        int ny = y + dir[p][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        b = (4 + b + bias[p]) % 4;
        p = (p + b) % 4;
        curr = curr->move(p);
        if (board[nx][ny] == 0) {
            board[nx][ny] = curr->value;
        }
        else {
            curr->value = board[nx][ny];
            board[nx][ny] = 0;
        }
        printf("[%d %d] -> [%d %d] %d %d\n", x, y, nx, ny, p, curr->id);
        x = nx, y = ny;
        printf("%d\n", curr->front());
    }
}

int main() {

    make_dice();

    read_input();

    run();

    return 0;
}