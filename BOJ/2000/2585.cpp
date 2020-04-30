#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

#define SQ(x) ((x)*(x))
typedef pair<double, double> P;
typedef pair<int,int> Pii;

const int MAX_INF = 1e9;
const int MAX_N = 1003;
const int MAX_L = 1500;

int N, K;
P pos[MAX_N];

int getDistance(P &a, P &b) {
	double ret = sqrt(SQ(a.first - b.first)+SQ(a.second - b.second));
	return (ret-(int)ret > 0) ? ((int)ret/10) + 1 : ((int)ret/10);
}

int check(int L) {
	int dist[MAX_N];
	bool visited[MAX_N];
	fill(dist, dist+MAX_N, MAX_INF);
	fill(visited, visited+MAX_N, false);
	dist[0] = 0;
	priority_queue<Pii, vector<Pii>, greater<Pii> > PQ;
	PQ.push(Pii(0, 0));
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);
		if (visited[curr]) break;
		visited[curr] = true;
		for (int i=1; i<N; i++) {
			if (i == curr) continue;
			if (getDistance(pos[curr], pos[i]) > L) continue;
			if (dist[i] > dist[curr] + 1) {
				dist[i] = dist[curr] + 1;
				PQ.push(Pii(dist[i], i));
			}
		}
	}

	return dist[N-1]-1;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i=1; i<=N; i++)
		scanf("%lf%lf", &pos[i].first, &pos[i].second);
	N+=2;
	pos[0].first = pos[0].second = 0.f;
	pos[N-1].first = pos[N-1].second = 10000.f;

	int ret = MAX_L;
	int left = 0, right = MAX_L;
	while (left <= right) {
		int mid = (left+right)/2;
		if (check(mid) > K) {
			left = mid + 1;
		} else {
			ret = min(ret, mid);
			right = mid-1;
		}
	}
	printf("%d\n", ret);
	return 0;
}