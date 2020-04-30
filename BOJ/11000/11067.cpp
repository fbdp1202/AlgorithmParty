// baekjoon 11067 yechan
#include <cstdio>
#include <map>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_N=100001;

int T, N, M;
pair<int,int> data[MAX_N];
map<int, pair<int,int> > m;
bool visited[MAX_N];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(visited, 0, sizeof(visited));
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			scanf("%d%d", &data[i].first, &data[i].second);
		}
		sort(data, data+N);

		int i = 0;
		int now = 0;
		int num = 1;
		int cur_x = 0;
		while (i < N) {
		}
		scanf("%d", &M);
		for (int i=0; i<M; i++) {
			int x;
			scanf("%d", &x);
			pair<int,int> ans = m[x];
			printf("%d %d\n", ans.first, ans.second);
		}
	}

	return 0;
}