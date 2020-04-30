// baekjoon 5046 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_INF=1e9;
int N, B, H, W;
int p, a;
int main() {
	scanf("%d%d%d%d", &N, &B, &H, &W);
	int bound=B/N;
	int minP=MAX_INF;
	for (int i=0; i<H; i++) {
		scanf("%d", &p);
		bool flag = (p <= bound);
		for (int j=0; j<W; j++) {
			scanf("%d", &a);
			if (flag && N <= a) minP=min(minP, p);
		}
	}
	if (minP == MAX_INF) printf("stay home\n");
	else printf("%d\n", minP*N);
	return 0;
}