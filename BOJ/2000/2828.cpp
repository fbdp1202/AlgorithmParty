// baekjoon 2828 yechan
#include <bits/stdc++.h>
using namespace std;

int N, M;
int s, j, ret;

int main() {
	scanf("%d%d", &N, &M);
	scanf("%d", &j);
	s=1;
	for (int i=0; i<j; i++) {
		int x; scanf("%d", &x);
		if (s <= x && x <= s+M-1) continue;
		if (x < s) {
			ret += s - x;
			s = x;
		} else {
			ret += x - (s+M-1);
			s = x-M+1;
		}
	}
	printf("%d\n", ret);
	return 0;
}