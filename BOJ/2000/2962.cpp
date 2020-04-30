// baekjoon 2962 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=101;

ll T;
int N, M;
ll animal[2][MAX_N][2];

ll getNum(int idx, ll t, int len) {
	ll ret = 0;
	for (int i=0; i<len; i++)
		if (t >= animal[idx][i][0])
			ret += 1 + (t - animal[idx][i][0])/animal[idx][i][1];
	return ret;
}

int main() {
	scanf("%lld", &T);
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%lld%lld", &animal[0][i][0], &animal[0][i][1]);

	scanf("%d", &M);
	for (int i=0; i<M; i++)
		scanf("%lld%lld", &animal[1][i][0], &animal[1][i][1]);

	ll left=1, right=T;
	ll ret=T;
	while (left <= right) {
		ll mid = (left + right)/2;
		ll num1 = getNum(0, mid, N);
		ll num2 = getNum(1, T-mid, M);
		if (num1 < num2) {
			left = mid + 1;
		} else {
			ret = min(ret, mid);
			right = mid - 1;
		}
	}
	printf("%lld\n", ret);
	return 0;
}