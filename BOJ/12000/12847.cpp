// baekjoon 12827 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=100001;

int N, M;
int arr[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	ll ret = 0, ans = 0;
	for (int i=0; i<M; i++)
		ans += arr[i];

	ret = max(ret, ans);
	for (int i=M; i<N; i++) {
		ans -= arr[i-M];
		ans += arr[i];
		ret = max(ret, ans);
	}
	printf("%lld\n", ret);
	return 0;
}