// baekjoon 12018 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=101;
int N, M, P, L, data[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i=0; i<N; i++) {
		scanf("%d%d", &P, &L);
		for (int j=0; j<P; j++)
			scanf("%d", &data[j]);
		sort(data, data+P, greater<int>());
		if (P < L) pq.push(1);
		else pq.push(data[L-1]);
	}
	int ret = 0;
	while (M && !pq.empty()) {
		if (pq.top() > M) break;
		M -= pq.top();
		ret++;
		pq.pop();
	}
	printf("%d\n", ret);
	return 0;
}