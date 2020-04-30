// baekjoon 4153 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c;

int main() {
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (!(a || b || c)) break;
		if (a > b) swap(a, b);
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);
		if (c*c == a*a + b*b ) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
	return 0;
}