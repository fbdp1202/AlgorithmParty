#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=500001;
typedef pair<int,int> P;
typedef long long ll;

int T, M, N, x, y;
P pos[MAX_N];
ll ret;

int main() {
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test=1; test<=T; test++) {
		ret = 0;
		printf("Case #%d\n", test);
		scanf("%d", &M);
		scanf("%d", &N);
		for (int i=0; i<N; i++)
			scanf("%d%d", &pos[i].first, &pos[i].second);

		sort(pos, pos+N);
		for (int i=0; i<N; i++) {
			int maxLen = min(M-pos[i].first, M-pos[i].second);
			for (int j=i+1; j<N; j++) {
				if (pos[j].first - pos[i].first > maxLen) break;
				if (pos[i].first == pos[j].first) continue;
				if (pos[i].second < pos[j].second) {
					maxLen = min(maxLen, max(pos[j].second - pos[i].second, pos[j].first - pos[i].first));
				}
			}
			ret = ret + maxLen;
		}
		printf("%lld\n", ret);
	}
	return 0;
}