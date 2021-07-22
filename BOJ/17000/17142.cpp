// baekjoon 17142 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=51;
const int MAX_M=11;
const int MAX_INF=1e9;

const int dir[4][2] = {
    { 0, -1},
    {-1,  0},
    { 1,  0},
    { 0,  1}
};

int N, M, K;
int board[MAX_N][MAX_N];
int stage[MAX_N][MAX_N];

vector<P> virus;
int indices[MAX_M];

bool visited[MAX_N][MAX_N];
int remain;

void read_input() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            scanf("%d", &board[i][j]);

    remain = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            if (board[i][j] == 2)
                virus.push_back(P(i, j));
            else if (board[i][j] == 0)
                remain++;
        }

    K = virus.size();
}

int infer() {
    int ret = 0;
    if (remain == 0) return ret;

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            stage[i][j] = board[i][j];

    memset(visited, 0, sizeof(visited));

    queue<P> q;
    for (int i=0; i<M; i++) {
        int x = virus[indices[i]].first;
        int y = virus[indices[i]].second;
        q.push(virus[indices[i]]);
        visited[x][y] = true;
    }

    int c_remain = remain;

    while (!q.empty()) {
        ret++;

        int qSize = q.size();

        while (qSize--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int d=0; d<4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if (board[nx][ny] == 1) continue;

                if (visited[nx][ny]) continue;

                visited[nx][ny] = true;

                c_remain -= ((board[nx][ny] == 0) ? 1 : 0);

                q.push(P(nx, ny));
            }
        }
        if (c_remain == 0) return ret;
    }

    if (c_remain != 0) return MAX_INF;

    return ret;
}

int backtracking(int num, int start) {
    int ret = MAX_INF;

    if (num == M) {
        return infer();
    }

    if (M - num > K - start) {
        return MAX_INF;
    }

    for (int i=start; i<K; i++) {
        indices[num] = i;
        ret = min(ret, backtracking(num+1, i+1));
    }

    return ret;
}

int run() {
    int ret = MAX_INF;

    ret = backtracking(0, 0);

    ret = (ret == MAX_INF) ? -1 : ret;

    return ret;
}

int main() {

    read_input();

    printf("%d\n", run());

    return 0;
}