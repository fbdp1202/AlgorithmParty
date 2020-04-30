// baekjoon 4880 yechan
#include <bits/stdc++.h>
using namespace std;

int main() {
	while (1) {
		int a1, a2, a3;
		scanf("%d%d%d", &a1, &a2, &a3);
		if (!a1 && !a2 && !a3) break;
		bool AP = (a1-a2) == (a2-a3);
		if (AP) printf("AP %d\n", a3 + (a3-a2));
		else printf("GP %d\n", a3 * (a3/a2));
	}
	return 0;
}