#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<P, P>;

const int MAX_N=21;
const int MAX_M=MAX_N*MAX_N;

const int dir[4][2] = {
    {-1, 0},
    { 0,-1},
    { 1, 0},
    { 0, 1}
};

const int score[5] = {
    0, 1, 10, 100, 1000
};

int N, M;
int board[MAX_N][MAX_N];
int likes[MAX_M][4];
int indices[MAX_M];

void PrintBoard()
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            printf("%d ", board[i][j]);
        }
        puts("");
    }
    puts("");
}

int read_int()
{
    int x; scanf("%d", &x);
    return x;
}

void read_inputs()
{
    N = read_int();
    M = N*N;
    for (int i=0; i<M; i++)
    {
        int idx = read_int();
        indices[i] = idx;
        for (int d=0; d<4; d++)
        {
            likes[idx][d] = read_int();
        }

    }
}

int getResult()
{
    int ret = 0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int idx = board[i][j];
            int num = 0;
            for (int d=0; d<4; d++)
            {
                int nx = i + dir[d][0];
                int ny = j + dir[d][1];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                for (int k=0; k<4; k++)
                {
                    if (board[nx][ny] == likes[idx][k]) {
                        num++;
                    }
                }
            }
            ret += score[num];
        }
    }
    return ret;
}

int run()
{
    for (int i=0; i<M; i++)
    {
        int idx = indices[i];

        vector<PP> recomends;
        for (int x=0; x<N; x++)
        {
            for (int y=0; y<N; y++)
            {
                // is not empty
                if (board[x][y] != 0) continue;

                int num_likes = 0;
                int num_blank = 0;

                // search near block
                for (int d=0; d<4; d++)
                {
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];
                    // out of range
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    // is empty
                    if (!board[nx][ny]) { num_blank++; continue; }

                    for (int k=0; k<4; k++)
                        if (board[nx][ny] == likes[idx][k])
                            num_likes++;
                }
                recomends.emplace_back(PP(P(-num_likes, -num_blank), P(x, y)));
            }
        }
        sort(recomends.begin(), recomends.end());
        int x = recomends[0].second.first;
        int y = recomends[0].second.second;
        board[x][y] = idx;
    }

    int ret = getResult();
    return ret;
}

int main()
{
    read_inputs();

    printf("%d\n", run());
    return 0;
}