// baekjoon 1449 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;

int N, L, holl[MAX_N];

int main() {
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; i++)
		scanf("%d", &holl[i]);
	sort(holl, holl+N);

	int last = 0;
	int ret = 0;
	for (int i=0; i<N; i++) {
		if (holl[i] < last) continue;
		ret++;
		last = holl[i]+L;
	}
	printf("%d\n", ret);
	return 0;
}