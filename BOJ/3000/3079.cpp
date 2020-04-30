// baekjoon 3079 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 100001;
const ll MAX_INF = (1LL<<62);

ll N, M;
ll arr[MAX_N];

bool check(ll t) {
	ll num = 0;
	for (int i=0; i<N; i++) {
		num += t/arr[i];
		if (num >= M) return true;
	}
	return num >= M;
}

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%lld", &arr[i]);

	ll left=0, right=MAX_INF;
	ll ret=MAX_INF;
	while (left <= right) {
		ll mid = (left+right)/2;
		if (check(mid)) right = mid - 1, ret = min(ret, mid);
		else left = mid + 1;
	}
	printf("%lld\n", ret);

	return 0;
}