// baekjoon 11652 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1000000;
typedef long long ll;

int N;
ll arr[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr+N);

	ll prev = arr[0];
	int maxcnt = 0;
	ll maxV = arr[0];
	int cnt = 0;

	for (int i=0; i<N; i++) {
		if (prev == arr[i]) {
			cnt++;
			if (maxcnt < cnt) {
				maxcnt = cnt;
				maxV = arr[i];
			}
		} else {
			cnt = 1;
			prev = arr[i];
		}
	}
	printf("%lld\n", maxV);
	return 0;
}