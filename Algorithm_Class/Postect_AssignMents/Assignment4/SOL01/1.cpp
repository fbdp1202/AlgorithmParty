// postech algo problem Assign #4-1 exhibition
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N=300001;
int T, N, f, d;
P data[MAX_N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		priority_queue<int> pq;
		for (int i=0; i<N; i++) scanf("%d%d", &data[i].second, &data[i].first); // (fee, days)
		sort(data, data+N, greater<P>());

		int i=0;
		ll ret=0;
		int cur_day=data[0].first;
		while (cur_day) {
			while (i != N && data[i].first == cur_day) pq.push(data[i++].second);
			if (!pq.empty()) {
				ret += pq.top(); pq.pop();
			}
			cur_day--;
		}
		printf("%lld\n", ret);
	}
	return 0;
}
