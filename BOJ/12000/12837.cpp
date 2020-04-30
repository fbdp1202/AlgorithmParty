// baekjoon 12837 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<20;
typedef long long ll;
int N, Q, cmd, p, q;
ll arr[SIZE*2];

ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

ll sum(int L, int R) {
	return sum(L, R, 1, 0, SIZE-1);
}

void update(int i, int val) {
	i += SIZE;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}

int main() {
	scanf("%d %d", &N, &Q);
	while (Q--) {
		scanf("%d %d %d", &cmd, &p, &q);
		if (cmd == 1) {
			update(p-1, q);
		} else {
			printf("%lld\n", sum(p-1, q-1));
		}
	}
	return 0;
}