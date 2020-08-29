#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;
const int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

int N, M;
int board[MAX_N][MAX_N];
int b[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int dfs(int x, int y, int z) {
    b[x][y] = z;
    int ret = 1;
    visited[x][y] = true;
    for (int d=0; d<4; d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visited[nx][ny]) continue;
        if (board[nx][ny]) continue;
        ret += dfs(nx, ny, z);
    }
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%1d", &board[i][j]);

    vector<int> v;
    v.push_back(0);
    int z = 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!board[i][j] && !visited[i][j]) {
                v.push_back(dfs(i,j,z));
                z++;
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j]) {
                set<int> s;
                for (int d=0; d<4; d++) {
                    int nx = i + dir[d][0];
                    int ny = j + dir[d][1];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    s.insert(b[nx][ny]);
                }
                for (auto k : s) board[i][j] += v[k];
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            printf("%d", board[i][j] % 10);
        }
        puts("");
    }
    return 0;
}