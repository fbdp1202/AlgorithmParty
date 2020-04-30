// baekjoon 12738 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1000001;
const int MAX_INF=2e9;

int N, data[MAX_N], LIA[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);

	fill(LIA, LIA+N+1, MAX_INF);
	for (int i=0; i<N; i++) {
		int idx = lower_bound(LIA, LIA+N+1, data[i]) - LIA;
		LIA[idx] = data[i];
	}

	int pos = 1;
	for (int i=0; i<N; i++) {
		if (LIA[i] == MAX_INF) {
			pos = i;
			break;
		}
	}
	printf("%d\n", pos);
	return 0;
}