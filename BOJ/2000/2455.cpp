// baekjoon 2455 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a, b, result=0, tmp=0;
	for (int i=0; i<4; i++) {
		result = max(result, tmp);
		scanf("%d %d", &a, &b);
		tmp -=a;
		tmp +=b;
		result = max(result, tmp);
	}
	printf("%d\n", result);
	return 0;
}