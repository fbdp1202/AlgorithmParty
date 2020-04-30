// baekjoon 1948 yechan
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=10001;
typedef pair<int,int> P;

int N, M, u, v, w, S, E;
int load[MAX_N];
int length[MAX_N];
int indeg[MAX_N];
vector<P> adj[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(P(v, w));
		indeg[v]++;
	}
	scanf("%d%d", &S, &E);

	queue<int> q;
	q.push(S);
	0for (int i=0; i<N; i++) {
		int cur_v = q.front();
		q.pop();
		for (int j=0; j<adj[cur_v].size(); j++) {
			int nv = adj[cur_v][j].first;
			int nt = adj[cur_v][j].second;
			if (length[nv] < length[cur_v] + nt) {
				length[nv] = length[cur_v] + nt;
				load[nv] = load[cur_v] + 1;
			} else if (length[nv] == length[cur_v] + nt) {
				load[nv] += load[cur_v] + 1;
			}
			if (--indeg[nv] == 0) {
				q.push(nv);
			}
		}
	}
	printf("%d\n%d\n", length[E], load[E]);
	return 0;
}