// blog.kyouko.moe/m/61
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

enum State  {WHITE, BLACK, GRAY} ;

bool dfs(const vector<vector<int>>& conn, vector<State>& visit, int a)
{
    if (visit[a] == BLACK) return false;
    if (visit[a] == GRAY) return true;

    visit[a] = GRAY;
    for (int x: conn[a])
        if (dfs(conn, visit, x))
            return true;
    visit[a] = BLACK;

    return false;
}

bool hasCycle(const vector<vector<int>>& conn)
{
    vector<State> visit(conn.size(), WHITE);
    for (int i=0; i<(int)conn.size(); ++i)
        if (dfs(conn, visit, i))
            return true;

    return false;
}

string solve(int N, vector<pair<int, int> > O, vector<pair<int, int> > U)
{
    vector<vector<int> > conn(N);
    for (auto [u, v]: O) conn[u-1].push_back(v-1);

    string ans;
    for (auto [u, v]: U)
    {
        --u; --v;
        conn[u].push_back(v);
        if (hasCycle(conn))
        {
            conn[u].pop_back();
            conn[v].push_back(u);
            ans += '1';
        } else ans += '0';
    }
    return ans;
}

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; ++t)
    {
        int N, M, K; cin >> N >> M >> K;
        vector<pair<int, int> > O, U;
        for (int i=0; i<M; ++i)
        {
            int a, b; scanf("%d%d", &a, &b);
            O.emplace_back(a, b);
        }
        for (int i=0; i<K; ++i)
        {
            int a, b; scanf("%d%d", &a, &b);
            U.emplace_back(a, b);
        }
        cout << "Case #" << t << '\n' << solve(N, O, U) << endl;
    }
}
