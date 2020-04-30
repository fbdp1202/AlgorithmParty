// baekjoon 3006 yechan
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int SIZE = 1<<17;
int N, arr[SIZE*2];
P data[SIZE];

int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}
int sum(int L, int R) { return sum(L, R, 1, 0, SIZE-1); }

void update(int i, int val) {
	i += SIZE;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
} 

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &data[i].first);
		data[i].second = i;
		update(i, 1);
	}
	sort(data+1, data+N+1);

	for (int i=1; i<=N; i++) {
		if (i % 2) {
			update(data[i/2+1].second, 0);
			printf("%d\n", sum(0, data[i/2+1].second));
		} else {
			update(data[N-i/2+1].second, 0);
			printf("%d\n", sum(data[N-i/2+1].second, N));
		}
	}
}