// baekjoon 2933 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N = 101;
const int dir[4][2] = {
    { 0,-1},
    { 0, 1},
    {-1, 0},
    { 1, 0}
};

int N, M, K;

char board[MAX_N][MAX_N];

int stick[MAX_N];
int visited[MAX_N][MAX_N];

void read_inputs()
{
    scanf("%d%d", &N, &M);
    for (int i=N-1; i>=0; i--)
        scanf("%s", board[i]);

    scanf("%d", &K);
    for (int i=0; i<K; i++)
        scanf("%d", &stick[i]);
}

void PrintBoard()
{
    for (int i=N-1; i>=0; i--)
        printf("%s\n", board[i]);
}

int getCrashPoint(int y, int flag)
{
    int minP = M, maxP = -1;

    for (int i=0; i<M; i++)
    {
        if (board[y][i] == 'x')
        {
            minP = min(minP, i);
            maxP = max(maxP, i);
        }
    }
    if (maxP == -1) return -1;
    if (!flag) return minP;
    return maxP;
}

bool dfs(int x, int y, int idx)
{
    bool ret = (x == 0);
    visited[x][y] = idx;

    for (int d=0; d<4; d++)
    {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] == '.') continue;
        if (visited[nx][ny]) continue;
        ret |= dfs(nx, ny, idx);
    }
    return ret;
}

void Throw(int x, int flag)
{
    int y = getCrashPoint(x, flag);
    // no break point
    if (y == -1) return;
    board[x][y] = '.';
    memset(visited, 0, sizeof(visited));

    int idx = 0;
    for (int d=0; d<4; d++)
    {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] == '.') continue;
        if (visited[nx][ny]) continue;
        bool ret = dfs(nx, ny, ++idx);
        if (!ret) {
            int sink = N;

            for (int j=0; j<M; j++)
            {
                int bottom = -1;
                int up = -1;
                for (int i=N-1; i>=0; i--)
                {
                    if (board[i][j] == '.') continue;
                    if (visited[i][j] == idx) {
                        bottom = i;
                        if (bottom < up) up = -1;
                    }
                    else up = max(up, i);
                }
                if (bottom == -1) continue;
                int local_sink = bottom - up - 1;
                sink = min(sink, local_sink);
            }
            for (int j=0; j<M; j++)
            {
                for (int i=0; i<N; i++)
                {
                    if (visited[i][j] == idx)
                    {
                        board[i][j] = '.';
                        board[i-sink][j] = 'x';
                    }
                }
            }
        }
    }
}

void run()
{
    for (int i=0; i<K; i++)
    {
        Throw(stick[i]-1, i%2);
    }
}

int main()
{
    read_inputs();

    run();

    PrintBoard();
    return 0;
}