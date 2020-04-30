// baekjoon 11504 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, K, x;
int data[101];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);

		long long X = 0, Y = 0;
		for (int i=0; i<K; i++) {
			X *= 10;
			scanf("%d", &x);
			X += x;
		}
		for (int i=0; i<K; i++) {
			Y *= 10;
			scanf("%d", &x);
			Y += x;
		}
		for (int i=0; i<N; i++)
			scanf("%d", &data[i]);

		int ret = 0;
		for (int i=0; i<N; i++) {
			long long ans = 0;
			for (int j=0; j<K; j++) {
				ans *= 10;
				ans += data[(i+j)%N];
			}
			if (X <= ans && ans <= Y) ret++;
		}
		printf("%d\n", ret);
	}
	return 0;
}