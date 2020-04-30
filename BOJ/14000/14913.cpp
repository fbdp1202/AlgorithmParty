// baekjoon 14913 yechan
#include <cstdio>
using namespace std;

int a, d, k, result;

int main() {
	scanf("%d%d%d", &a, &d, &k);
	result = 1+(k-a)/d;
	if((k-a)%d || result <= 0) printf("X");
	else printf("%d", result);
	return 0;
}