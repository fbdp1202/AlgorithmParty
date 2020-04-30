// baekjoon 3745 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
const int SIZE = 1<<17;
typedef pair<int, int> P;

int N, arr[SIZE*2];
P data[SIZE];

int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return max(sum(L, R, nodeNum*2, nodeL, mid), sum(L, R, nodeNum*2+1, mid+1, nodeR));
}
int sum(int L, int R) { return sum(L, R, 1, 0, SIZE-1); }

void update(int i, int val) {
	i += SIZE;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		arr[i] = max(arr[i*2], arr[i*2+1]);
	}
}

int main() {
	while (scanf("%d", &N) != -1) {
		if (N == 0) {
			printf("0\n");
			continue;
		}

		for (int i=0; i<N; i++) {
			scanf("%d", &data[i].first);
			data[i].second = -i;
		}
		fill(arr, arr+SIZE*2, 0);
		sort(data, data+N);
		for (int i=0; i<N; i++) {
			update(-data[i].second, sum(0, -data[i].second) + 1);
		}
		printf("%d\n", arr[1]);
	}
	return 0;
}