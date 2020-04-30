// baekjoon 9345 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<17;
const int INF = 1e9;

int T, N, K, Q, A, B;
int minHeap[SIZE*2], maxHeap[SIZE*2]; 
// flag (1:max, 0:min)
int sum(int *arr, int L, int R, int nodeNum, int nodeL, int nodeR, int flag) {
	if (R < nodeL || nodeR < L) return (flag) ? 0 : SIZE;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	if(flag)
		return max(sum(arr, L, R, nodeNum*2, nodeL, mid, flag), sum(arr, L, R, nodeNum*2+1, mid+1, nodeR, flag));
	else
		return min(sum(arr, L, R, nodeNum*2, nodeL, mid, flag), sum(arr, L, R, nodeNum*2+1, mid+1, nodeR, flag));
}
int sum(int *arr, int L, int R, int flag) { return sum(arr, L, R, 1, 0, SIZE-1, flag); }

void update(int *arr, int i, int val, int flag) {
	i+=SIZE;
	arr[i]=val;
	while (i > 1) {
		i /= 2;
		if (flag) arr[i] = max(arr[i*2], arr[i*2+1]);
		else 	  arr[i] = min(arr[i*2], arr[i*2+1]);
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		fill(minHeap, minHeap+SIZE*2, -INF);
		fill(maxHeap, maxHeap+SIZE*2, INF);
		scanf("%d%d", &N, &K);
		for (int i=0; i<N; i++) {
			update(minHeap, i, i, 0);
			update(maxHeap, i, i, 1);
		}

		for (int i=0; i<K; i++) {
			scanf("%d%d%d", &Q, &A, &B);
			if (Q) {
				if (sum(minHeap, A, B, 0) == A && sum(maxHeap, A, B, 1) == B) puts("YES");
				else puts("NO");
			} else {
				int tmp = minHeap[A+SIZE];
				update(minHeap, A, minHeap[B+SIZE], 0);
				update(maxHeap, A, maxHeap[B+SIZE], 1);
				update(minHeap, B, tmp, 0);
				update(maxHeap, B, tmp, 1);
			}
		}
	}

	return 0;
}