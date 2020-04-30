// baekjoono 17526 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

typedef long long ll;
typedef pair<ll,int> P;

const int MAX_N=100001;
const ll MAX_INF=(1LL<<62);

int N;
ll x, ride[MAX_N], sum[MAX_N], dist[MAX_N], speed[MAX_N];
bool visited[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=1; i<N; i++) {
		scanf("%lld", &x);
		sum[i+1] = sum[i] + x;
	}
	for (int i=1; i<N; i++)
		scanf("%lld%lld", &ride[i], &speed[i]);

	fill(dist, dist+MAX_N, MAX_INF);
	priority_queue<P, vector<P>, greater<P> > PQ;
	PQ.push(P(ride[1], 1));
	dist[1]=ride[1];
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);
		if (visited[curr]) break;
		if (curr == N) break;
		visited[curr] = true;
		for (int i=curr+1; i<=N; i++) {
			if (speed[curr] <= speed[i]) continue;
			ll d = (sum[i]-sum[curr])*speed[curr] + ride[i];
			if (dist[i] > dist[curr] + d) {
				dist[i] = dist[curr] + d;
				PQ.push(P(dist[i], i));
			}
		}
	}
	printf("%lld\n", dist[N]);
	return 0;
}