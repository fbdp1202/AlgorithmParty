// baekjoon 10800 yechan
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N=200001;
typedef pair<pair<int, int>, int> P;

int N, arr[MAX_N], ans[MAX_N], c, s, sum, tmp, cur_size;

priority_queue<P, vector<P>, greater<P>> PQ;
queue<int> Q;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d%d", &c, &s);
		PQ.push(P({s, c}, i));
	}

	while (!PQ.empty()) {
		cur_size=PQ.top().first.first;
		while (!PQ.empty() && PQ.top().first.first == cur_size) {
			ans[PQ.top().second] = sum - arr[PQ.top().first.second];
			Q.push(PQ.top().first.second);
			PQ.pop();
		}
		sum += Q.size()*cur_size;
		while (!Q.empty()) {
			arr[Q.front()] += cur_size;
			Q.pop();
		}
	}

	for (int i=0; i<N; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}