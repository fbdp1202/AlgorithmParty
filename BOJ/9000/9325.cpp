// baekjoon 9325 yechan
#include <bits/stdc++.h>
using namespace std;


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int s, N, q, p;
		scanf("%d", &s);
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			scanf("%d%d", &q, &p);
			s += p*q;
		}
		printf("%d\n", s);
	}
	return 0;
}