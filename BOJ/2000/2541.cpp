// baekjoon 2541 yechan
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int n = abs(a-b);
	while (n>0 && n%2==0) n/=2;

	for (int i=0; i<5; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int c = x-y;
		if (n == 0) puts((c==0)? "Y":"N");
		else puts(((abs(c)%n==0) && (1LL*c*(a-b)>0)) ? "Y":"N");
	}
	return 0;
}