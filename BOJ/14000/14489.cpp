// baekjoon 14489 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int A, B, C, result;

int main() {
	scanf("%d %d %d", &A, &B, &C);
	result=A+B;
	if (result >= 2*C) {
		result -= 2*C;
	}
	printf("%d", result);
	return 0;
}
