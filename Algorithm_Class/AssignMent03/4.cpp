// algo Problem Assginment #3 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<pair<ll, ll>, int> Plli; // (distance, price, arrival)
typedef pair<ll, int> Pli;
const int MAX_P=1001;
const int MAX_S=100001;
const ll MAX_INF=0x3FFFFFFFFFFFFF;

int T, P, S, u, v;
ll M, p, d, ret;
vector<int> visited;
vector<vector<Plli> > adj;
vector<ll> dist;

int main() {
	scanf("%d", &T);
	while (T--) {
		ret = MAX_INF;

		scanf("%d%d%lld", &P, &S, &M);
		adj = vector<vector<Plli> >(P);
		for (int i=0; i<S; i++) {
			scanf("%d%d%lld%lld", &u, &v, &p, &d);
			adj[u].push_back(Plli({d,p},v));
		}

		ll left=0, right=MAX_INF;
		while (left <= right) {
			ll mid = (left + right)/2;

			visited = vector<int>(P, 0);
			dist = vector<ll>(P, MAX_INF);
			priority_queue<Pli, vector<Pli>, greater<Pli> > PQ;

			dist[0]=0;
			PQ.push(Pli(0,0));
			while (!PQ.empty()) {
				int curr;
				do {
					curr = PQ.top().second;
					PQ.pop();
				} while (!PQ.empty() && visited[curr]);
				if (visited[curr]) break;
				visited[curr] = true;
				for (Plli &plane : adj[curr]) {
					if (mid < plane.first.second) continue;
					int next = plane.second;
					ll d = plane.first.first;
					if (dist[next] > dist[curr] + d) {
						dist[next] = dist[curr] + d;
						PQ.push(Pli(dist[next], next));
					}
				}
			}
			if (M < dist[P-1]) {
				left = mid+1;
			} else {
				ret = min(ret, mid);
				right = mid-1;
			}
		}
		if (ret == MAX_INF) ret = -1;
		printf("%lld\n", ret);
	}
	return 0;
}
