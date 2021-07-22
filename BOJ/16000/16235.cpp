// baekjoon 16235 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<int, P>;

const int MAX_N=11;
const int MAX_K=1001;
const int dir[8][2] = {
    {-1, -1},
    {-1,  0},
    {-1,  1},
    { 0, -1},
    { 0,  1},
    { 1, -1},
    { 1,  0},
    { 1,  1}
};

int N, M, K;
int A[MAX_N][MAX_N];
int board[MAX_N][MAX_N];

deque<PP> trees;
queue<P> updates;
queue<PP> deads;

void read_input() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &A[i][j]);
            board[i][j] = 5;
        }
    }

    vector<PP> _trees;
    for (int i=0; i<M; i++) {
        int x, y, o;
        scanf("%d%d%d", &x, &y, &o);
        _trees.push_back(PP(o, P(x-1, y-1)));
    }
    sort(_trees.begin(), _trees.end());

    for (int i=0; i<M; i++)
        trees.push_back(_trees[i]);
}

void spring() {
    int nlife = trees.size();
    for (int i=0; i<nlife; i++) {
        PP tree = trees.front();
        trees.pop_front();

        int old = tree.first;
        int x = tree.second.first;
        int y = tree.second.second;

        if (board[x][y] < old) {
            deads.push(PP(old, P(x, y)));
        } else {
            board[x][y] -= old;
            trees.push_back(PP(old+1, P(x, y)));
            if ((old+1) % 5 == 0) {
                updates.push(P(x, y));
            }
        }
    }
}

void summer() {
    while (!deads.empty()) {
        PP dead = deads.front();
        deads.pop();

        int energy = (int)(dead.first / 2);
        int x = dead.second.first;
        int y = dead.second.second;
        board[x][y] += energy;
    }
}

void autumn() {

    while (!updates.empty()) {
        int x = updates.front().first;
        int y = updates.front().second;
        updates.pop();

        for (int d=0; d<8; d++) {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            trees.push_front(PP(1, P(nx, ny)));
        }
    }
}

void winter() {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            board[i][j] += A[i][j];
}

int run() {
    for (int i=0; i<K; i++) {
        spring();
        summer();
        autumn();
        winter();
        if (trees.size() == 0) return 0;
    }
    return trees.size();
}

int main() {
    read_input();
    printf("%d\n", run());
    return 0;
}