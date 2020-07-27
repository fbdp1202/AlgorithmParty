#include <bits/stdc++.h>
using namespace std;

int N, a, total, x;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &x);
		total += x;
		a += x/2;
	}
	puts((total % 3 == 0 && a >= total/3) ? "YES" : "NO");
	return 0;
}