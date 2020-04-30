// baekjoon 1654 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_K=10001;

int K;
ll N;
int line[MAX_K];

bool check(ll here) {
	ll sum = 0;
	for (int i=0; i<K; i++)
		sum += line[i]/here;
	return sum >= N;
}

int main() {
	scanf("%d%lld", &K, &N);
	for (int i=0; i<K; i++)
		scanf("%d", &line[i]);

	ll left = 1, right = (1LL<<61);
	ll ret = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			ret = max(ret, mid);
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	printf("%lld\n", ret);
	return 0;
}