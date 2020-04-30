// baekjoon 9625 yechan
#include <bits/stdc++.h>
using namespace std;

int main() {
	int K;
	scanf("%d", &K);
	int pvA=1, pvB=0;
	int curA=0, curB=0;
	for (int i=0; i<K; i++) {
		curA = pvB;
		curB = pvA + pvB;
		pvA = curA, pvB = curB;
	}
	printf("%d %d\n", curA, curB);
	return 0;
}