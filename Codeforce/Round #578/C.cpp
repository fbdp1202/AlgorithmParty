#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, M, Q;


ll gcd(ll x, ll y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main()
{
	ll sx, sy, ex, ey;
	scanf("%lld%lld%lld", &N, &M, &Q);
	ll gMax = gcd(max(N,M), min(N,M));
	ll gN = N/gMax;
	ll gM = M/gMax;
	for (int i=0; i<Q; i++) {
		scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
		if (sx == 1) {
			sy = (sy-1)/gN;
		} else {
			sy = (sy-1)/gM;
		}
		if (ex == 1) {
			ey = (ey-1)/gN;
		} else {
			ey = (ey-1)/gM;
		}
		puts( (sy == ey) ? "YES":"NO");
	}
	return 0;
}