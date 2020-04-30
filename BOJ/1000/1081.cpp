// baekjoon 1081 yechan
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

ll L, U, Lidx, Uidx, dp[12];

ll pow_10(ll n){ ll rst = 1; while (n--) rst*=10; return rst; }

inline ll f(ll n) { return n*pow_10(n-1); }

ll calc(ll n, int digit)
{
	ll rst = 0;
	if (digit == 1) {
		for (int i=1; i<=n; i++)
			rst += i;
		return rst;
	}
	ll power = pow_10(digit-1);
	ll p = n / power;
	ll q = n % power;
	rst += p*45*f(digit-1);
	for (int i=1; i<p; i++)
		rst += i*power;
	rst += p*(q+1);
	rst += calc(q, digit-1);
	return rst;
}

int main()
{
	scanf("%lld%lld", &L, &U);
	if (U == 0) return !printf("0\n");
	ll rst = calc(U, (int)log10(1.0*U)+1);
	if (L>1) rst -= calc(L-1, (int)log10(L-1.0)+1);
	printf("%lld\n", rst);
	return 0;
}