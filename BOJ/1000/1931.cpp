// baekjoon 1931 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=100001;

int N;
P meeting[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		meeting[i] = P(y, x);
	}
	sort(meeting, meeting+N);

	int cur = -100;
	int ret = 0;
	for (int i=0; i<N; i++) {
		if (cur > meeting[i].second) continue;
		cur = meeting[i].first;
		ret++;
	}
	printf("%d\n", ret);
	return 0;
}