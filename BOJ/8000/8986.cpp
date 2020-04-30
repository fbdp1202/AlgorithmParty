// baekjoon 8986 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=100001;
const ll MAX_INF=1e9;
const ll MAX_V=(1LL<<62);

int N;
ll arr[MAX_N];

ll dist(ll d) {
	ll ret = 0;
	for (int i=1; i<N; i++)
		ret += abs(arr[i]-d*i);
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%lld", &arr[i]);

	ll left=0, right=MAX_INF;
	while (right - left > 10) {
		ll mid1 = (left * 2 + right)/3;
		ll mid2 = (left + right*2)/3;
		ll d1 = dist(mid1);
		ll d2 = dist(mid2);
		if (d1 == d2) left = mid1, right = mid2;
		else if (d1 > d2) left = mid1;
		else right = mid2;
	}
	ll ret = MAX_V;
	for (ll i=left; i<=right; i++)
		ret = min(ret, dist(i));
	printf("%lld\n", ret);
	return 0;
}