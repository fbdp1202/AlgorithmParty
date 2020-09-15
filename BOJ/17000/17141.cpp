// baekjoon 17141 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=51;
const int MAX_M=11;
const int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
const int MAX_INF=1e9;

int N, M;
int numBlock;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<P> virus;
P choose[MAX_M];

int bfs();

int dfs(int here, int num) {
    if (num == 0) {
        return bfs();
    }
    if (here == virus.size()) return MAX_INF;
    int ret = MAX_INF;
    // not choose
    ret = min(ret, dfs(here+1, num));
    // choose here
    choose[num-1] = virus[here];
    ret = min(ret, dfs(here+1, num-1));
    return ret;
}

int bfs() {
    int ret = 0;
    int tmpBlock = numBlock;
    memset(visited, 0, sizeof(visited));
    queue<P> q;
    for (int i=0; i<M; i++) {
        q.push(choose[i]);
        visited[choose[i].first][choose[i].second] = true;
        tmpBlock--;
    }

    while (!q.empty()) {
        int qSize = q.size();
        for (int qs=0; qs<qSize; qs++) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int d=0; d<4; d++) {
                int nx = cx + dir[d][0];
                int ny = cy + dir[d][1];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (visited[nx][ny]) continue;
                if (board[nx][ny] == 1) continue;

                visited[nx][ny] = true;
                tmpBlock--;
                q.push(P(nx, ny));
            }
        }

        if (!q.empty()) ret++;
    }

    return (tmpBlock == 0) ? ret : MAX_INF;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 2) {
                virus.push_back(P(i,j));
            }
            if (board[i][j] != 1){
                numBlock++;
            }
        }
    }

    int ret = dfs(0, M);
    if (ret == MAX_INF) ret = -1;
    printf("%d\n", ret);
    return 0;
}