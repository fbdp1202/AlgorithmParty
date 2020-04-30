// baekjoon 11501 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1000000;

int N, data[MAX_N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long ans = 0;
		scanf("%d", &N);
		for (int i=0; i<N; i++)
			scanf("%d", &data[i]);

		int maxV = 0;
		for (int i=N-1; i>=0; i--)
		{
			if (maxV < data[i]) {
				maxV = data[i];
			} else {
				ans += (maxV - data[i]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}