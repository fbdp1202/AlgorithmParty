// baekjoon 2089 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, i;

int main() {
	scanf("%d", &N);
	while (N) {
		int r = N%(-2);
		if (r == -1) printf("11");
		else printf("%d", r);
		N/=-2;
	}
	return 0;
}