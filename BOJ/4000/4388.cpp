// baekjoon 4388 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A, B;

int main() {
	while (1) {
		scanf("%d%d", &A, &B);
		if (!A && !B) break;
		int ret = 0;
		int C = 0;
		while (A || B || C) {
			C = C + A%10 + B%10;
			if (C >= 10) ret++;
			A/=10, B/=10, C/=10;
		}
		printf("%d\n", ret);
	}
	return 0;
}