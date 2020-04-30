// baekjoon 2042 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int SIZE = 1<<20;
int N, M, K;
ll arr[SIZE*2];

struct SegTree{
	ll sum(int L, int R) { return sum(L, R, 1, 0, SIZE-1); }
	ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
		if (R < nodeL || nodeR < L) return 0;
		if (L <= nodeL && nodeR <= R) return arr[nodeNum];
		int mid = (nodeL + nodeR) / 2;
		return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
	}

	void update(int i, ll val) {
		i += SIZE;
		arr[i] = val;
		while (i > 1) {
			i /= 2;
			arr[i] = arr[i*2] + arr[i*2+1];
		}
	}
};

int main() {
	scanf("%d%d%d", &N, &M, &K);
	SegTree sg;

	for (int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		sg.update(i, x);
	}
	for (int i=0; i<M+K; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			sg.update(b-1, c);
		} else {
			printf("%lld\n", sg.sum(b-1,c-1));
		}
	}
	return 0;
}