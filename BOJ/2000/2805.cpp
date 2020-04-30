// baekjoon 2805 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N=1000001;

int N;
ll M, height[MAX_N];

bool check(ll h) {
	ll sum = 0;
	for (int i=0; i<N; i++) {
		if (sum >= M) return true;
		sum += max(0LL, height[i]-h);
	}
	return sum>=M;
}

int main() {
	scanf("%d%lld", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%lld", &height[i]);

	ll left = 1, right = 1e9;
	ll ret = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			left = mid + 1;
			ret = max(ret, mid);
		} else {
			right = mid - 1;
		}
	}
	printf("%lld\n", ret);
	return 0;
}