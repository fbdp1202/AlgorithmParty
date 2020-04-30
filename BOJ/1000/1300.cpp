// baekjoon 1300 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=10001;
const ll MAX_INF=(1LL<<62);

int N;
ll K;

bool check(ll here) {
	ll sum = 0;
	for (int i=1; i<=N; i++)
		sum += min(1LL*N,here/i);
	return sum >= K;
}

int main() {
	scanf("%d%lld", &N, &K);
	ll left = 1, right = MAX_INF;
	ll ret = MAX_INF;
	while (left <= right) {
		ll mid = (left + right)/2;
		if (check(mid)) {
			right = mid - 1;
			ret = min(ret, mid);
		} else {
			left = mid + 1;
		}
	}
	printf("%d\n", ret);
	return 0;
}