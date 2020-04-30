// baekjoon 1484 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int s, e;
ll d, G;
vector<ll> v;
bool flag;

int main() {
	scanf("%lld", &G);
	for (ll i=1; i<=(G+1)/2; i++) {
		v.push_back(i*i*1LL);
	}

	while (1) {
		d = v[e]-v[s];
		if (d >= G) {
			if (d == G) {
				printf("%d\n", e+1);
				flag = true;
			}
			s++;
		} else if (e == v.size()) {
			break;
		} else {
			e++;
		}
	}

	if (!flag) puts("-1");
	return 0;
}