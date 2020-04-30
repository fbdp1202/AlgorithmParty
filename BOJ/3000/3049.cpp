#include <cstdio>
typedef long long LL;
LL n, data[101];

LL f(LL n) {
	return ((n-2)*(n-3)*(n-2))/2 - ((n-3)*(n-2)*(2*n-5))/6;
}

int main() {
	scanf("%lld", &n);
	data[3] = 0;
	data[4] = 1;
	for (int i=5; i<n+1; i++) {
		data[i] = data[i-1] + f(i);
	}
	printf("%lld", data[n]);
	return 0;
}