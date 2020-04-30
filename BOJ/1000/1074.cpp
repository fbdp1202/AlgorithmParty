// baekjoon 1074 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, r, c;
ll Z(ll x, ll y, ll size) {
	if (x == r && y == c) return 0;
	size /= 2;
	if (r < x + size) {
		if (c < y + size) return Z(x, y, size);
		else return size*size+Z(x, y+size, size);
	} else {
		if (c < y + size) return size*size*2+Z(x+size, y, size);
		else return size*size*3+Z(x+size, y+size, size);
	}
}

int main() {
	scanf("%lld%lld%lld", &N, &r, &c);
	printf("%lld\n", Z(0,0,1LL<<N));
	return 0;
}