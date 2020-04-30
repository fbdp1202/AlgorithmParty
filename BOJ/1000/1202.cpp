// baekjoon 1202 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 300000
typedef pair<int, int> pii;

pii jew[MAX_N];
int N, K, bag[MAX_N];

int main() {
	scanf("%d %d", &N, &K);
	for (int i=0; i<N; i++) 
		scanf("%d %d", &jew[i].first, &jew[i].second);

	for (int i=0; i<K; i++)
		scanf("%d", &bag[i]);

	sort(jew, jew + N);
	sort(bag, bag + K);

	long long sum = 0;
	priority_queue<int> pq;
	for (int j=0, i=0; i<K; i++) {
		while (jew[j].first<=bag[i] && j<N)
			pq.push(jew[j++].second);

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	printf("%lld", sum);
	return 0;
}