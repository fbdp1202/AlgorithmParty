// baekjoon 1058
#include <iostream.>
#include <string.h>
#include <queue>

using namespace std;

#define ll long long
#define MOD (ll)1e15
#define MAX_SIZE 500000

char map[55][55];
bool visit[55];
int n;

int bfs(int vertex){
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int> > q;
	q.push(make_pair(vertex, 0));
	visit[vertex] = 1;

	while(!q.empty()) {
		int now = q.front().first;
		int breath = q.front().second;
		q.pop();

		if(breath == 2) break;

		for (int i = 0; i < n; ++i)
		{
			if(map[now][i] == 'Y' && !visit[i]) {
				visit[i] = 1;
				q.push(make_pair(i, breath + 1));
			}
		}
	}

	int ret = 0;
	for(int i = 0; i < n; i++) ret += visit[i];

	return ret - 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	int ret = 0;
	for(int i = 0; i < n; i++) ret = max(ret, bfs(i));

	cout << ret;

	return 0;
}