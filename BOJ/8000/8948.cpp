// baekjoon 8948 yechan
#include <bits/stdc++.h>
using namespace std;

int A, B;
int ret[7];

int main() {
	scanf("%d%d", &A, &B);
	int maxpos = 0;
	int pos = 0;
	while (A) {
		ret[pos++] = A%10;
		A/=10;
	}
	maxpos = pos;
	pos = 0;
	while (B) {
		ret[pos++] += B%10;
		B/=10;
	}
	maxpos = max(maxpos, pos);
	for (int i=maxpos-1; i>=0; i--)
		printf("%d", ret[i]);
	puts("");
	return 0;
}