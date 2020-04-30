// baekjoon 1629 yechan
#include <bits/stdc++.h>
using namespace std;

int A, B, C;

int pow(int a, int n) {
	if (n == 0) return 1;
	if (n == 1) return a;
	int ret = pow(a, n/2);
	ret = ((1LL*ret*ret)%C);
	if (n % 2) ret = (1LL*ret*a)%C;
	return ret;
}

int main() {
	scanf("%d%d%d", &A, &B, &C);
	printf("%d\n", pow(A, B)%C);
	return 0;
}