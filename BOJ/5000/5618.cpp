// baekjoon 5618 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int divisor, N, data[3], minV=987654321;

int gcd(int a, int b) {
	int mod = a % b;
	while (mod > 0) {
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d", &data[i]);
	}
	divisor = gcd(data[0], data[1]);
	if (N == 3) divisor = gcd(divisor, gcd(data[1], data[2]));

	for (int i=1; i<=divisor; i++)
		if (divisor%i == 0) 
			printf("%d\n", i);

	return 0;
}