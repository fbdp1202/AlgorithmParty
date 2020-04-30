// baekjoon 11505
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll DIV_NUM = 1000000007;
const int size = 1<<20;

ll arr[size*2];

int N, M, K;

struct SegTree {
	SegTree() {}

	ll sum(int L, int R) { 
		if (R < 0 || size-1 < L) return 0;
		return sum(L, R, 1, 0, size-1);
	}
	ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
		if (R < nodeL || nodeR < L) return 1;
		if (L <= nodeL && nodeR <= R) return arr[nodeNum];
		int mid = (nodeL + nodeR) / 2;
		return (sum(L, R, nodeNum*2, nodeL, mid) * sum(L, R, nodeNum*2+1, mid+1, nodeR)) % DIV_NUM;
	}

	void update(int i, ll val) {
		i += size;
		arr[i] = val;
		while (i > 1) {
			i /= 2;
			arr[i] = (arr[i*2] * arr[i*2+1]) % DIV_NUM;
		}
	}
};

int main () {
	SegTree sg;
	scanf("%d %d %d", &N, &M, &K);
	for (int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		sg.update(i, x);
	}

	for (int i=0; i<M+K; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			sg.update(b-1, c);
		} else {
			printf("%lld\n", sg.sum(b-1, c-1) % DIV_NUM);
		}
	}
	return 0;
}
