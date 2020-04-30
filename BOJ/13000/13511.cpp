// baekjoon 13511 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_N=100001;
const int MAX_K=18;

int N, M;
ll dp[MAX_N][MAX_K];
int parent[MAX_N][MAX_K];
vector<P> adj[MAX_N];
int depth[MAX_N];

void makeTreeByDFS(int here) {
	for (int i=0; i<adj[here].size(); i++) {
		int there = adj[here][i].first;
		if (depth[there] != -1) continue;
		int w = adj[here][i].second;
		parent[there][0] = here;
		dp[there][0] = w;
		depth[there] = depth[here] + 1;
		makeTreeByDFS(there);
	}
}

int main()
{
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	scanf("%d", &N);
	for (int i=0; i<N-1; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		adj[u].push_back(P(v,w));
		adj[v].push_back(P(u,w));
	}

	makeTreeByDFS(0);

	for (int j=0; j<MAX_K-1; j++) {
		for (int i=0; i<N; i++) {
			if (parent[i][j] != -1 && parent[parent[i][j]][j] != -1) {
				parent[i][j+1] = parent[parent[i][j]][j];
				dp[i][j+1] = dp[i][j] + dp[parent[i][j]][j];
			}
		}
	}

	int M;
	scanf("%d", &M);
	while (M--) {
		int cmd, u, v, k;
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d%d", &u, &v);
			u--, v--;
			if (depth[u] < depth[v]) swap(u, v);
			int diff = depth[u] - depth[v];

			ll ret = 0;
			for (int j=0; diff; j++) {
				if (diff & 1) {
					ret += dp[u][j];
					u = parent[u][j];
				}
				diff /= 2;
			}

			if (u != v) {
				for (int j=MAX_K-1; j>=0; j--) {
					if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
						ret += dp[u][j];
						ret += dp[v][j];
						u = parent[u][j];
						v = parent[v][j];
					}
				}
				ret += dp[u][0] + dp[v][0];
			}
			printf("%lld\n", ret);
		} else {
			scanf("%d%d%d", &u, &v, &k);
			u--, v--;
			int ou = u, ov =v;
			int num_u=0, num_v=0;

			if (depth[u] > depth[v]) {
				int diff = depth[u] - depth[v];
				num_u += diff;
				for (int i=0; diff; i++) {
					if (diff % 2) u = parent[u][i];
					diff /= 2;
				}
			} else {
				int diff = depth[v] - depth[u];
				num_v += diff;
				for (int i=0; diff; i++) {
					if (diff % 2) v = parent[v][i];
					diff /= 2;
				}
			}

			if (u != v) {
				for (int i=MAX_K-1; i>=0; i--) {
					if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
						num_u += (1<<i);
						num_v += (1<<i);
						u = parent[u][i];
						v = parent[v][i];
					}
				}
				num_u++;
				num_v++;
			}
			k--;
			if (k <= num_u) {
				u = ou;
				for (int i=0; k; i++) {
					if (k % 2) u = parent[u][i];
					k /= 2;
				}
				printf("%d\n", u+1);
			}
			else {
				v = ov;
				k = num_v - (k - num_u);
				for (int i=0; k; i++) {
					if (k % 2) v = parent[v][i];
					k /= 2;
				}
				printf("%d\n", v+1);
			}
		}
	}

	return 0;
}