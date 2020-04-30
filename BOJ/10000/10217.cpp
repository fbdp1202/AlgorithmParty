// baekjoon 10217 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
const int MAX_N=101;
const int MAX_K=10001;
int T, N, M, K, u, v, c, d;
bool visited[MAX_N];

pair<int, int> dist[MAX_N];
pair<int, int> adj[MAX_N][MAX_N];
vector<int> cost;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &M, &K);
		for (int i=0; i<K; i++) {
			scanf("%d%d%d%d", &u, &v, &c, &d);
			adj[u][v] = {c, d};
			cost.push_back(c);
		}
		sort(cost.begin(), cost.end());
		cost.erase(unique(cost.begin(), cost.end()), cost.end());

		int costSize = cost.size();
		int ans = 1e9;
		for (int i=0; i < costSize; i++) {
			int left = i;
			int right = costSize-1;
			int ret = 1e9;
			while (left <= right) {
				int mid = (left+right)/2;
				for (int i=1; i<=N; i++)
					dist[i]={1e9, 1e9};
				memset(visited, 0, sizeof(visited));
				priority_queue<pair<pair<int,int>,int> , vector<pair<pair<int,int>,int> >, greater<pair<pair<int,int>,int> > > PQ;

				PQ.push({{0,0}, 1}); // ((time, cost), to)
				dist[1]={0,0}; // (time, cost)
				while (!PQ.empty()) {
					int cur;
					do {
						cur = PQ.top().second;
						PQ.pop();
					} while (!PQ.empty() && visited[cur]);

					visited[cur]=true;
					for (int k=1; k<=N; k++) {
						auto &p = adj[cur][k];
						if (!p.first && !p.second) continue;
						if (!(cost[i] <= p.first && p.first <= cost[mid])) continue;
						if (dist[cur].first > dist[k].first + p.second) {
							dist[cur].first = dist[k].first + p.second;
							dist[cur].second = dist[k].second + p.first;
							PQ.push({{dist[cur].first, dist[cur].second}, k});
						}
					}
				}
				if (dist[N].second <= M && dist[N].first < ret) {
					ret = min(dist[N].first, ret);
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			ans = min(ans, ret);
		}
		printf("%d\n", ans);
	}
	return 0;
}