// baekjoon 4641 yechan
#include <bits/stdc++.h>
using namespace std;

bool values[201];

int main() {
	while (1) {
		int x;
		scanf("%d", &x);
		if (x == -1) break;
		fill(values, values+201, false);
		values[x] = true;
		while (1) {
			scanf("%d", &x);
			if (x == 0) break;
			values[x] = true;
		}

		int ret = 0;
		for (int i=1; i<=100; i++) {
			if (values[i] && values[i*2]) ret++;
		}
		printf("%d\n", ret);
	}
	return 0;
}