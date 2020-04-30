#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAX_LL=(1LL<<62);
const int MAX_N=250001;

int T, N;
ll a, b;
char s[MAX_N];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%lld%lld", &N, &a, &b);
		scanf("%s", s);

		bool check = (a <= b);
		if (check) {
			bool car = false;
			for (int i=0; i<N; i++) {
				if (s[i] == '1') car = true;
			}
			if (car) printf("%lld\n", b*2 + a*(N-2));
			else printf("%lld\n", a*N);
		}
		else {
			ll ret = 0;
			int cur = 0;
			for (int i=0; i<N-1; i++) {
				if (s[i] == '1') ret += a;
				else {
					if (cur) {
						if (s[i+1] == '1') ret += a;
						else ret += b, cur=0;
					} else {
						ret += b, cur=1;
					}
				}
			}
			if (cur) ret += b;
			else ret += a;
			printf("%lld\n", ret);
		}
	}
	return 0;
}
