// baekjoon 12015 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int SIZE = 1<<20;
typedef pair<int,int> P;

int N;
int arr[SIZE*2];
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

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &data[i].first);
		data[i].second = -i;
	}
	sort(data, data+N);
	for (int i=0; i<N; i++) {
		update(-data[i].second, sum(0, -data[i].second) + 1);
	}
	printf("%d\n", arr[1]);
	return 0;
}