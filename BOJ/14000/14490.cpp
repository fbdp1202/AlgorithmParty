// baekjoon 14490 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int N, M;
	scanf("%d:%d", &N, &M);
	int g = gcd(N, M);
	printf("%d:%d\n", N/g, M/g);
	return 0;
}