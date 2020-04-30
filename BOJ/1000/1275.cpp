// baekjoon 1275 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<17;
typedef long long ll;

int N, Q;
ll data, arr[SIZE*2];

ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}
ll sum(int L, int R) { return sum(L, R, 1, 0, SIZE-1); }

void update(int i, ll val) {
	i += SIZE;
	arr[i]=val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i=0; i<N; i++){
		scanf("%lld", &data);
		update(i, data);
	}
	for (int i=0; i<Q; i++) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		printf("%lld\n", sum(x-1, y-1));
		update(a-1, (ll)b);
	}
	return 0;
}