// baekjoon 2476 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, a, b, c, result;
int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a > b) swap(a, b);
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);

		if (a == b && b == c)
			result = max(result, 10000+a*1000);
		else if (a == b || b == c)
			result = max(result, 1000+100*b);
		else
			result = max(result, 100*c);
	}
	printf("%d\n", result);
	return 0;
}