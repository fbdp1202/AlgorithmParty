// baekjoon 9613 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, arr[100];

int gcd(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i=0; i<N; i++)
			scanf("%d", &arr[i]);
		long long sum = 0;
		for (int i=0; i<N-1; i++) {
			for (int j=i+1; j<N; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}