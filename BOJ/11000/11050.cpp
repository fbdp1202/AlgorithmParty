// baekjoon 11050 yechan
#include <cstdio>

int f(int num) {
	if(num == 0) return 1;
	return f(num-1)*num;
}

int comb(int n, int k) {
	return f(n)/f(k)/f(n-k);
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	printf("%d", comb(N,K));
	return 0;
}