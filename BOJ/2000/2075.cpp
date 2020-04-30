// baekjoon 2075 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int N, x;

int main() {
	priority_queue<int, vector<int>, greater<int>> PQ;
	scanf("%d", &N);
	for (int j=0; j<N; j++) {
		scanf("%d", &x);
		PQ.push(x);
	}
	for (int i=1; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%d", &x);
			PQ.push(x);
			PQ.pop();
		}
	}

	printf("%d\n", PQ.top());
	return 0;
}