// baekjoon 3216 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100001;
int N;

int main() {
	scanf("%d", &N);
	int ret = 0;
	int D, V;
	int remain = 0;
	for (int i=0; i<N; i++) {
		scanf("%d%d", &D, &V);
		remain -= V;
		if (remain < 0) ret += remain, remain=0;
		remain += D;
	}
	printf("%d\n", ret);
	return 0;
}