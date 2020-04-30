// baekjoon 2268 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<20;
typedef long long ll;
int N, Q, a, b, c;
ll arr[SIZE*2];

void update(int i, ll val) {
	i+=SIZE;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}

ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

ll sum(int L, int R) { return sum(L, R, 1, 0, SIZE-1); }

int main() {
	scanf("%d%d", &N, &Q);
	while (Q--) {
		scanf("%d%d%d", &a, &b, &c);
		if (a) update(b-1, c);
		else printf("%lld\n", sum(b-1, c-1));
	}
	return 0;
}