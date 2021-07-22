// baekjoon 19237 yechan
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N=21;
const int MAX_M=MAX_N*MAX_N;
const int MAX_K=1001;

const int dir[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
};

int N, M, K;
pair<int, int> board[MAX_N][MAX_N];

struct Shark{
    int idx;
    int curr_dir;
    int cx, cy;
    bool life;
    vector<vector<int>> prior_dir;

    explicit Shark(int i, int x, int y, int _curr_dir,
                    vector<vector<int>> _prior_dir)
    {
        idx = i;
        cx = x, cy = y;
        curr_dir    = _curr_dir;
        prior_dir   = _prior_dir;
        life        = true;
    }

    void Move(int t)
    {
        int move_dir = -1;
        // find no smell place
        for (int d=0; d<4; d++)
        {
            int nd = prior_dir[curr_dir][d];
            int nx = cx + dir[nd][0];
            int ny = cy + dir[nd][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (t - board[nx][ny].second <= K) continue;
            move_dir = d;
            break;
        }
        if (move_dir != -1)
        {
            curr_dir = prior_dir[curr_dir][move_dir];
            int nx = cx + dir[curr_dir][0];
            int ny = cy + dir[curr_dir][1];
            cx = nx;
            cy = ny;
            return;
        }

        // fine my smell place
        for (int d=0; d<4; d++)
        {
            int nd = prior_dir[curr_dir][d];
            int nx = cx + dir[nd][0];
            int ny = cy + dir[nd][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (idx != board[nx][ny].first) continue;
            move_dir = d;
            break;
        }
        if (move_dir != -1)
        {
            curr_dir = prior_dir[curr_dir][move_dir];
            cx = cx + dir[curr_dir][0];
            cy = cy + dir[curr_dir][1];
            return;
        }
    }
};

vector<Shark> sharks;

void PrintBoard()
{
    printf("\nPrintBoard\n");
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int x, y;
            x = board[i][j].first;
            y = (board[i][j].second == -1e9) ? -1 : board[i][j].second;
            printf("%2d %2d, ", x, y);
        }
        puts("");
    }
    puts("");
}

void PrintShark()
{
    printf("\nPrintSharks\n");
    for (int i=0; i<M; i++)
    {
        int idx = sharks[i].idx;
        int x = sharks[i].cx;
        int y = sharks[i].cy;
        int d = sharks[i].curr_dir;
        bool life = sharks[i].life;
        printf("(%d) -> [%d %d %d] (%d)\n", idx, x+1, y+1, d, (int)(life));
    }
    puts("");
}

void solve()
{
    int remain = M;

    stack<int> state[MAX_N][MAX_N];
    for (int t=1; t<=1000; t++)
    {
        for (int i=0; i<M; i++)
        {
            if (!sharks[i].life) continue;
            sharks[i].Move(t);
        }

        for (int i=0; i<M; i++)
        {
            if (!sharks[i].life) continue;
            int x = sharks[i].cx;
            int y = sharks[i].cy;
            state[x][y].push(sharks[i].idx);
        }

        // kill sharks
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                int stSize = state[i][j].size();
                while (stSize--)
                {
                    int idx = state[i][j].top();
                    state[i][j].pop();
                    if (stSize != 0) {
                        sharks[idx-1].life = false;
                        remain--;
                    }
                }
            }
        }

        // update smells
        for (int i=0; i<M; i++)
        {
            if (!sharks[i].life) continue;
            int x = sharks[i].cx;
            int y = sharks[i].cy;
            board[x][y] = {i+1, t};
        }


        if (remain == 1)
        {
            printf("%d\n", t);
            return;
        }
    }
    puts("-1");
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);

    vector<pair<int, int>> pos(M);
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int x; scanf("%d", &x);
            board[i][j] = {x, ((x == 0) ? -1e9 : 0)};
            if (x != 0)
                // pos[board[i][j] - 1] = make_pair(i, j);
                pos[x-1] = {i, j};
        }
    }

    vector<int> direction;
    for (int i=0; i<M; i++)
    {
        int x; scanf("%d", &x);
        direction.push_back(x-1);
    }

    vector<vector<vector<int>>> list_prior_dir;
    for (int i=0; i<M; i++)
    {
        vector<vector<int>> prior_dir(4);
        for (int j=0; j<4; j++)
        {
            for (int k=0; k<4; k++) {
                int d; scanf("%d", &d);
                prior_dir[j].push_back(d-1);
            }
        }
        list_prior_dir.push_back(prior_dir);
    }

    for (int i=0; i<M; i++)
    {
        int x = pos[i].first;
        int y = pos[i].second;
        int d = direction[i];
        sharks.push_back(Shark(i+1, x, y, d, list_prior_dir[i]));
    }

    solve();

    return 0;
}