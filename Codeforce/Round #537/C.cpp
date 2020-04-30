// Round 537 C.cpp yechan
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
const int MAX_K = 100001;
int N, K, A, B;
int avenger[MAX_K];

ll tracking(int start, int end) {
	int Na = lower_bound(avenger, avenger+K, end+1) - upper_bound(avenger, avenger+K, start-1);
	ll ret = 0x3c3c3c3c3c3c3c3c;
	if (!Na) ret = min(ret, 1LL*A);
	else ret = min(ret, 1LL*B*Na*(end-start+1));

	if (start == end) return ret;
	return min(ret, tracking(start, start + (end-start)/2) + tracking(start + (end-start)/2 + 1, end));
}

int main() {
	scanf("%d%d%d%d", &N, &K, &A, &B);
	for (int i=0; i<K; i++)
		scanf("%d", &avenger[i]);

	sort(avenger, avenger+K);
	printf("%lld\n", tracking(1, 1<<N));
	return 0;
}