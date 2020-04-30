// baekjoon 2248 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 32
typedef long long ll;

int N, L;
ll I, c[MAX_N][MAX_N], cSum[MAX_N][MAX_N];

ll comb(int n, int r) {
	if (n < 0 || r < 0 || n < r) return 0;
	if (n==0 || n==r || r==0) return c[n][r]=1;
	if (c[n][r]) return c[n][r];
	return c[n][r] = comb(n-1, r-1)+comb(n-1,r);
}

ll pcomb(int n, int r) {
	if (n < 0 || r < 0) return 0;
	r = min(n,r);
	if (cSum[n][r]) return cSum[n][r];
	return cSum[n][r] = comb(n, r) + pcomb(n, r-1);
}

void tracking(int n, int l, ll k) {
	if (n == 0) return;
	// printf("tracking(%d, %d, %d)", n, l, k);
	ll cnt = pcomb(n-1,l);
	// printf(": comb(%d, %d)= %d\n", n-1, l, cnt);
	if (k > cnt) {
		printf("1");
		tracking(n-1, l-1, k-cnt);
	} else {
		printf("0");
		tracking(n-1, l, k);
	}
}

int main() {
	scanf("%d%d%lld", &N, &L, &I);
	tracking(N,L,I);
	puts("");
	return 0;
}