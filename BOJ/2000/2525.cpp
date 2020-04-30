// baekjoon 2525 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A, B, C;
int main() {
	scanf("%d %d %d", &A, &B, &C);
	int result = (A*60 + B + C)%1440;
	printf("%d %d\n", result/60, result%60);
	return 0;
}