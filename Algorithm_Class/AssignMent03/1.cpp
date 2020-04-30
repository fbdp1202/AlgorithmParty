// algo postech Assignment #3 1.cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MAX_N=3001;
const ll MAX_INF=0x3c3c3c3c3c3c3c3c;

int T, V, E;
vector<ll> dp;
vector<vector<P> > adj;

ll dfs(int start) {
	ll &ret = dp[start];
	if (ret != -1) return ret;
	ret = 0;
	for (auto x : adj[start])
		ret = max(ret, x.second + dfs(x.first));
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &V, &E);
		ll ret = 0;
		adj = vector<vector<P> >(V+1);
		vector<int> indeg(V+1);
		dp = vector<ll>(V+1, -1);

		for (int i=0; i<E; i++) {
			ll u, v, w;
			scanf("%lld%lld%lld", &u, &v, &w);
			adj[u].push_back(P(v,w));
			indeg[v]++;
		}

		for (int i=0; i<V; i++)
			if (!indeg[i])
				ret = max(ret, dfs(i));
		printf("%lld\n", ret);
	}
	return 0;
}