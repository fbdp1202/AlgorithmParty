// baekjoon 1493 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N=20;

int N;
ll cube[MAX_N], cnt, ret;

int main() {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	scanf("%d", &N);
	for (int i=0, x, y; i<N; i++) scanf("%d%d", &x, &y), cube[x] = y;

	for (int i=19; i>=0; i--) {
		cnt <<= 3;
		ll tmp = min(cube[i], 1LL*(A>>i)*(B>>i)*(C>>i)-cnt);
		cnt += tmp, ret += tmp;
	}
	printf("%lld\n", (cnt == 1LL*A*B*C ? ret : -1));
	return 0;
}