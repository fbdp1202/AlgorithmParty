// baekjoon 13904 yechan
#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;

const int MAX_N=1001;

int N;
P work[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int d, w;
		scanf("%d%d", &d, &w);
		work[i] = P(d, w);
	}
	sort(work, work+N);

	int cur = work[N-1].first;
	int ret = 0;
	int pos = N-1;
	priority_queue<int> PQ;
	while (cur) {
		while (pos >= 0 && cur == work[pos].first) {
			PQ.push(work[pos].second);
			pos--;
		}

		if (!PQ.empty()) {
			ret += PQ.top();
			PQ.pop();
		}
		cur--;
	}
	printf("%d\n", ret);
	return 0;
}