// baekjoon 5032 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int e, f, c, result;

int main() {
	scanf("%d%d%d", &e, &f, &c);
	e+=f;
	while (e >= c) {
		result += e/c;
		e = e%c + e/c;
	}
	printf("%d\n", result);
	return 0;
}