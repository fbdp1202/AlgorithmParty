// baekjoon 3653 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<18;

int T, N, M, arr[SIZE*2], idx[SIZE];

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
	scanf("%d", &T);
	while (T--) {
		fill(arr, arr+SIZE*2, 0);
		scanf("%d%d", &N, &M);
		for (int i=1; i<=N; i++) {
			update(N-i+1, 1);
			idx[i]=N-i+1;
		}
		for (int i=N+1; i<=N+M; i++) {
			int x; scanf("%d", &x);
			update(idx[x], 0);
			printf("%d ", sum(idx[x], SIZE-1));
			idx[x]=i;
			update(idx[x], 1);
		}
		puts("");
	}
	return 0;
}