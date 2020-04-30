// Postech algo Ploblem Assignment #4-2 Flood
#include <cstdio>
#include <cstring>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int> > P;
const int MAX_V=3001;
const ll MAX_INF=0x7FFFFFFFFFFFFFF;
int T, V, E, u, v;
ll w;
int root[MAX_V];

int find(int x) {
	if (root[x] == -1) return x;
	return root[x]=find(root[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (a > b) swap(a, b);
	root[b] = a;
	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(root, -1, sizeof(root));
		scanf("%d%d", &V, &E);
		ll ret = MAX_INF;
		priority_queue<P> pq;
		while (E--) {
			scanf("%d%d%lld", &u, &v, &w);
			pq.push(P(w, {u,v}));
		}

		int num = 0;
		while (!pq.empty() && num != V-1) {
			tie(u, v) = pq.top().second;
			if (merge(u, v)) ret = min(ret, pq.top().first), num++;
			pq.pop();
		}
		printf("%lld\n", ret);
	}
	return 0;
}