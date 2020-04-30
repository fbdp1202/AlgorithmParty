// baekjoon 7507 yechan
#include <cstdio>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

const int MAX_N = 50001;

int T, N;
pair<int,int> match[MAX_N];

int main()
{
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		printf("Scenario #%d:\n", t);
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			int d, s, e;
			scanf("%d%d%d", &d, &s, &e);
			s += d*2400;
			e += d*2400;
			match[i] = {e, s};
		}

		int ret = 0;
		int start = 0;

		sort(match, match+N);

		for (int i=0; i<N; i++) {
			if (start <= match[i].second) {
				ret++;
				start = match[i].first;
			}
		}
		printf("%d\n\n", ret);
	}
	return 0;
}