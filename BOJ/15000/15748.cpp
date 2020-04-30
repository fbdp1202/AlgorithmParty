// baekjoon 15748 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using ll = long long;

int L, N, a, b, cur;
ll ret;
priority_queue<P> PQ;

int main() {
	scanf("%d%d%d%d", &L, &N, &a, &b);
	for (int i=0; i<N; i++) {
		int x, c;
		scanf("%d%d", &x, &c);
		PQ.push(P(c, x));
	}

	while (!PQ.empty()) {
		while (!PQ.empty() && PQ.top().second <= cur) PQ.pop();
		if (PQ.empty()) break;
		ret += 1LL*PQ.top().first*(PQ.top().second-cur)*(a-b);
		cur = PQ.top().second;
		PQ.pop();
	}
	printf("%lld\n", ret);
	return 0;
}