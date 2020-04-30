// baekjoon 10101 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int result = a+b+c;
	if (result != 180){
		puts("Error");
	} else {
		if (a > b) swap(a, b);
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);

		if (a == b && b == c) {
			puts("Equilateral");
		}
		else if (a == b || b == c) {
			puts("Isosceles");
		}
		else {
			puts("Scalene");
		}
	}
	return 0;
}