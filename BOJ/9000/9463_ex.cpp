// baekjoon 9463 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int SIZE = 1 << 17;
typedef pair<int,int> P;

int T, N, x, arr[SIZE*2];
int data[SIZE], data2[SIZE];


void update(int i, int val) {
	i+=SIZE;
	arr[i]=val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}

int partsum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return partsum(L, R, nodeNum*2, nodeL, mid) + partsum(L, R, nodeNum*2+1, mid+1, nodeR);
}

int main() {
	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);
		memset(arr, 0, sizeof(arr));
		for (int i=1; i<=N; i++) {
			scanf("%d", &x);
			data[x] = i;
		}
		for (int i=1; i<=N; i++) {
			scanf("%d", &x);
			data2[i] = data[x];
		}

		long long cnt = 0;
		for (int i=1; i<=N; i++) {
			cnt += data2[i]-1-partsum(1, data2[i], 1, 1, SIZE-1);
			update(data2[i], 1);
		}
		printf("%lld\n", cnt);
	}
	return 0;
}