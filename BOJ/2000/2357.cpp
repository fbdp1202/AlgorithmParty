// baekjoon 2357 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int SIZE = 1<<17;
const int MAX_INF = 1000000001;

int minarr[SIZE*2];
int maxarr[SIZE*2];

int N, M, a, b;

int sum(int *arr, int L, int R, int nodeNum, int nodeL, int nodeR, int flag) {
	if (R < nodeL || nodeR < L) return (flag) ? 0 : MAX_INF;
	if (L <= nodeL && nodeR <= R) {
		if (flag) return arr[nodeNum];
		else return (arr[nodeNum]) ? arr[nodeNum] : MAX_INF;
	}
	int mid = (nodeL + nodeR) / 2;
	if (flag) return max(sum(arr, L, R, nodeNum*2, nodeL, mid, flag), sum(arr, L, R, nodeNum*2+1, mid+1, nodeR, flag));
	else return min(sum(arr, L, R, nodeNum*2, nodeL, mid, flag), sum(arr, L, R, nodeNum*2+1, mid+1, nodeR, flag));
}

int sum(int *arr, int L, int R, int flag) {
	return sum(arr, L, R, 1, 0, SIZE-1, flag);
}

void update(int *arr, int i, int val, int flag) {
	i += SIZE;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		if (flag) arr[i] = max(arr[i*2], arr[i*2+1]);
		else arr[i] = min(arr[i*2], arr[i*2+1]);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		update(minarr, i, x, 0);
		update(maxarr, i, x, 1);
	}

	for (int i=0; i<M; i++) {
		scanf("%d%d", &a, &b);
		printf("%d %d\n", sum(minarr, a-1, b-1, 0), sum(maxarr, a-1, b-1, 1));
	}
	return 0;
}