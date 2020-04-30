// baekjoon 2696 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N; scanf("%d", &N);
		printf("%d\n", (N+1)/2);
		priority_queue<int, vector<int>, greater<int>> maxHeap;
		priority_queue<int> minHeap;
		int mid; scanf("%d", &mid);
		printf("%d ", mid);
		for (int i=1; i<N; i++) {
			if (i % 20 == 0) puts("");
			int x; scanf("%d", &x);
			if (i%2 == 0) {
				int maxtop = maxHeap.top();
				int mintop = minHeap.top();
				if (x < mintop) {
					minHeap.push(x);
					mid = minHeap.top();
					minHeap.pop();
				} else {
					maxHeap.push(x);
					mid = maxHeap.top();
					maxHeap.pop();
				}
				printf("%d ", mid);
			} else {
				if (mid < x) {
					maxHeap.push(x);
					minHeap.push(mid);
				} else {
					maxHeap.push(mid);
					minHeap.push(x);
				}
			}
		}
		puts("");
	}
	return 0;
}
