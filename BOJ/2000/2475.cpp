// baekjoon 2475 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int ret, X;
int main() {
	for (int i=0; i<5; i++) {
		scanf("%d", &X);
		ret += X*X;
	}
	printf("%d\n", ret%10);
	return 0;
}