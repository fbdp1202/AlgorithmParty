// baekjoon 1280 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 200000;
const int SIZE = 1<<18;
const int MOD = 1000000007;

int N, x;
ll pos[SIZE*2];
ll num[SIZE*2];

ll sum(ll *arr, int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(arr, L, R, nodeNum*2, nodeL, mid) + sum(arr, L, R, nodeNum*2+1, mid+1, nodeR);
}

ll sum(ll *arr, int L, int R) { return sum(arr, L, R, 1, 0, SIZE-1); }

void update(ll *arr, int i, ll val) {
	i+=SIZE;
	arr[i]=val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}

int main() {
	scanf("%d", &N);
	ll ans = 1;
	scanf("%d", &x);
	update(pos, x, (ll)(pos[x+SIZE]+x));
	update(num, x, num[x+SIZE]+1);

	for (int i=1; i<N; i++) {
		scanf("%d", &x);
		ll left = sum(num, 0, x)*x - sum(pos, 0, x);
		ll right = sum(pos, x+1, MAX) - sum(num, x+1, MAX)*x;
		ll cost = (left + right)%MOD;
 		ans = (ans * cost) % MOD;
		update(pos, x, pos[x+SIZE]+x);
		update(num, x, num[x+SIZE]+1);
	}
	printf("%lld\n", ans);
	return 0;
}