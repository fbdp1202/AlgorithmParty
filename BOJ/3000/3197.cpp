#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<P, int>;

const int MAX_N=1501;
const int MAX_INF=1e9;
const int dir[4][2] = {
    { 0,-1},
    { 0, 1},
    {-1, 0},
    { 1, 0}
};

int N, M;
char board[MAX_N][MAX_N];

int dist[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

queue<P> water, ground, nWater, nGround;

bool explore()
{
    while (!ground.empty())
    {
        int x = ground.front().first;
        int y = ground.front().second;
        ground.pop();
        for (int d=0; d<4; d++)
        {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 'L') return true;

            visited[nx][ny] = true;
            if (board[nx][ny] == 'X') nGround.push({nx, ny});
            else ground.push({nx, ny});
        }
    }
    return false;
}

void melt()
{
    while (!water.empty())
    {
        int x = water.front().first;
        int y = water.front().second;
        water.pop();
        for (int d=0; d<4; d++)
        {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 'X')
            {
                board[nx][ny] = '.';
                nWater.push({nx, ny});
            }
        }
    }
}

int run(int sx, int sy, int dx, int dy)
{
    int ret = 0;
    ground.push({sx, sy});
    visited[sx][sy] = true;

    while (1)
    {
        if (explore()) return ret;
        melt();
        water = nWater;
        ground = nGround;
        while (!nWater.empty()) nWater.pop();
        while (!nGround.empty()) nGround.pop();
        ret++;
    }
    return -1;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++)
        scanf("%s", board[i]);

    vector<P> pos;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
        {
            if (board[i][j] == 'L')
                pos.push_back(P(i, j));
            if (board[i][j] != 'X')
                water.push({i, j});
        }

    int sx = pos[0].first;
    int sy = pos[0].second;
    int dx = pos[1].first;
    int dy = pos[1].second;

    printf("%d\n", run(sx, sy, dx, dy));
    return 0;
}