// baskjoon 16234
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int MAX_N=51;
const int MAX_S=101;
const int dir[4][2] = {
    {0,  1},
    { 1, 0},
    {0, -1},
    {-1, 0}
};

int N, L, R;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void read_input() {
    scanf("%d%d%d", &N, &L, &R);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            scanf("%d", &board[i][j]);
}

vector<P> arr;

int search(int x, int y) {
    int ret = 1;
    arr.push_back(P(x, y));
    for (int d=0; d<4; d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

        if (visited[nx][ny]) continue;

        int diff = board[x][y] - board[nx][ny];
        diff = (diff > 0) ? diff : -diff;
        if (diff < L || diff > R) continue;

        visited[nx][ny] = true;
        ret += search(nx, ny);
    }
    return ret;
}

int run() {
    int ret = 0;

    while (1) {
        memset(visited, 0, sizeof(visited));
        vector<vector<P>> v;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (visited[i][j]) continue;
                arr.clear();
                visited[i][j] = true;
                int ans = search(i, j);
                if (ans > 1) v.push_back(arr);
            }
        }

        if (v.size() == 0) return ret;

        for (auto &a : v) {
            int total = 0;

            for (auto &p : a) {
                int x = p.first;
                int y = p.second;
                total += board[x][y];
            }

            int change = (int)(total / a.size());

            for (auto &p : a) {
                int x = p.first;
                int y = p.second;
                board[x][y] = change;
            }
        }
        ret++;
    }
    return -1;
}

int main() {
    read_input();
    printf("%d\n", run());
    return 0;
}