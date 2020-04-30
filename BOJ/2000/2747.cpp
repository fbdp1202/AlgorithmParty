// baekjoon 2747 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

int N;
LL fibo[46];

LL f(int n) {
	if(~fibo[n]) return fibo[n];
	return fibo[n] = f(n-1) + f(n-2);
}

int main() {
	fill(fibo, fibo+46, -1);
	fibo[0]=0; fibo[1]=1;
	scanf("%d", &N);
	printf("%lld", f(N));
	return 0;
}