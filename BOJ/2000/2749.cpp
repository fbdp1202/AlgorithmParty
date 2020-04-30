// baekjoon 2749 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define DIV_NUM 1000000
#define MAX_NUM 90
typedef unsigned long long ll;

ll fibo[MAX_NUM+1], n;

int main() {
	scanf("%lld", &n);

	fibo[0] = 0; fibo[1] = 1;
	for (int i=2; i<=MAX_NUM; i++) {
		fibo[i] = (fibo[i-1] + fibo[i-2]);
	}

	printf("%lld\n", fibo[n]);
	return 0;
}