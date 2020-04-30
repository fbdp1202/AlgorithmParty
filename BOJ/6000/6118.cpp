// baekjoon 6118 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 20001;
const int INF = 987654321;
typedef pair<int, int> P;

int N, M, u, v, dist[MAX_N];
bool visited[MAX_N];
vector<int> adj[MAX_N];

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	fill(dist, dist+MAX_N, INF);

	priority_queue<P, vector<P>, greater<P>> PQ;

	dist[1] = 0;
	PQ.push(P(0, 1));
	while(!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);

		if(visited[curr]) break;

		visited[curr] = true;
		for (auto &next: adj[curr]) {
			if(dist[next] > dist[curr] + 1) {
				dist[next] = dist[curr] + 1;
				PQ.push(P(dist[next], next));
			}
		} 
	}

	int max_idx=0, max_dist=0, max_num=1;
	for (int i=1; i<=N; i++) {
		if (max_dist < dist[i]) {
			max_idx=i;
			max_dist=dist[i];
			max_num=1;
		}
		else if (max_dist == dist[i]) {
			max_num++;
		}
	}
	printf("%d %d %d", max_idx, max_dist, max_num);

	return 0;
}