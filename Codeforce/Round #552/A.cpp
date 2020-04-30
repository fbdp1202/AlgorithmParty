#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[4];

int main() {
	ll ret=0;
	for (int i=0; i<4; i++) {
		scanf("%lld", &arr[i]);
		ret += arr[i];
	}
	for (int i=0; i<4; i++) {
		if (ret/3 != arr[i]) {
			printf("%lld ", ret/3-arr[i]);
		}
	}
	return 0;
}