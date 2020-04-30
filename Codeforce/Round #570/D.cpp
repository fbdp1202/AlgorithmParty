#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=200001;

int q, N, x;
int cnt[MAX_N], num[MAX_N];

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &N);
		fill(num, num+N+1, 0);
		fill(cnt, cnt+N+1, 0);

		int maxCnt=0;
		for (int i=0; i<N; i++) {
			scanf("%d", &x);
			cnt[num[x]]--;
			num[x]++;
			cnt[num[x]]++;
			maxCnt = max(maxCnt, num[x]);
		}

		long long ret = 0;
		int count = 0;
		int remain=0;
		for (int i=maxCnt; i>0; i--) {
			remain += cnt[i];
			count += cnt[i]*i;
			if (remain) {
				ret += i;
				remain--;
			} else if (count == N) {
				break;
			}
		}
		printf("%lld\n", ret);
	}
	return 0;
}