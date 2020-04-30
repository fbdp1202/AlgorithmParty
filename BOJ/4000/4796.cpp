// baekjoon 4796 yechan
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T = 1;
	while (1) {
		int L, P, V;
		scanf("%d%d%d", &L, &P, &V);
		if (L + P + V == 0) break;
		printf("Case %d: %d\n", T++, (V/P)*L+min(L,V%P));
	}
	return 0;
}