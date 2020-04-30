// baekjoon 17521 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX_N=15;

ll N, W, data[MAX_N];

int main() {
	scanf("%lld%lld", &N, &W);
	for (int i=0; i<N; i++)
		scanf("%lld", &data[i]);

	ll ret = 0;
	ll num = 0;
	for (int i=0; i<N-1; i++) {
		if (data[i] < data[i+1]) {
			ll tmp = W/data[i];
			W -= tmp*data[i];
			num += tmp;
		}
		if (data[i] > data[i+1]) {
			W += num*data[i];
			num = 0;
		}
	}
	W += num*data[N-1];
	printf("%lld\n", W);
	return 0;
}