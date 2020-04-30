// baekjoon 7795 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_N = 20001;
const ll MAX_INF = (1LL<62);

int T, N, M;
ll Nlist[MAX_N], Mlist[MAX_N];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i=0; i<N; i++)
			scanf("%lld", &Nlist[i]);

		for (int i=1; i<=M; i++)
			scanf("%lld", &Mlist[i]);

		sort(Mlist, Mlist+M+1);

		int ret = 0;
		int idx = 0;
		for (int i=0; i<N; i++)
			ret += upper_bound(Mlist, Mlist+M+1, Nlist[i]-1) - Mlist - 1;
		printf("%d\n", ret);
	}
	return 0;
}