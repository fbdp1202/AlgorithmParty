// baekjoon 2721 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=301;

int T, N;
ll arr[MAX_N];

int main()
{
	ll a = 1;
	for (int i=1; i<MAX_N; i++) {
		a += i+1;
		arr[i] = arr[i-1] + i*a;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", arr[N]);
	}
}