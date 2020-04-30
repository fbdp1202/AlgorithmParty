// baekjoon 2588 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A, B, result, tmp;
int main() {
	scanf("%d %d", &A, &B);
	result = A*B;
	for (int i=0; i<3; i++) {
		tmp = A*(B%10);
		printf("%d\n", tmp);
		B/=10;
	}
	printf("%d\n", result);
	return 0;
}