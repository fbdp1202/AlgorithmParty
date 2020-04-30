// baekjoon 6502 yechan
#include <bits/stdc++.h>
using namespace std;
#define SQ(x) ((x)*(x))

int main() {
	for (int t=1; ; t++) {
		int r, w, l;
		scanf("%d", &r);
		if (r == 0) break;
		scanf("%d%d", &w, &l);
		printf("Pizza %d ", t);
		if (SQ(w)+SQ(l) <= SQ(r*2)) puts("fits on the table.");
		else puts("does not fit on the table.");
	}
	return 0;
}