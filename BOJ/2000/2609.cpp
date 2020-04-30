// baekjoon 2609 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a, b, result;
	scanf("%d%d", &a, &b);
	result = a*b;
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	printf("%d\n%d\n", a, result/a);
	return 0;
}