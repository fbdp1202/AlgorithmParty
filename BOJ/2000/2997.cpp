// baekjoon 2997 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);

	if( a-b != b-c) {
		if (b-a > c-b) {
			printf("%d", a + (b-a)/2);
		} else {
			printf("%d", b + (c-b)/2);
		}
	}
	else {
		if (2*c-b <= 100)
			printf("%d", 2*c-b);
		else 
			printf("%d", 2*a-b);
	}
	return 0;
}