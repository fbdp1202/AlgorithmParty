// baekjoon
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int T, N;
ll cnt;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		cnt = 0;
		for (ll i=5; i<=N; i*=5)
			cnt += N/i;
		printf("%lld\n", cnt);
	}
}