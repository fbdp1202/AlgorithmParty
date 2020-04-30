// baekjoon 13244 yechan
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

int T, N, M;
int cnt;
bool visited[MAX_N];
vector<vector<int> > adj;

bool dfs(int here, int prev)
{
	bool ret=true;
	visited[here]=true;
	cnt++;
	for (int next: adj[here]) {
		if (next == prev) continue;
		if (visited[next]) return false;
		ret &= dfs(next, here);
		if (!ret) return ret;
	}
	return ret;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(visited, 0, sizeof(visited));
		scanf("%d%d", &N, &M);
		adj = vector<vector<int> >(N);
		cnt = 0;
		for (int i=0; i<M; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--, y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		cnt = 0;
		if (dfs(0, -1) && cnt == N) {
			puts("tree");
		} else {
			puts("graph");
		}
	}
	return 0;
}