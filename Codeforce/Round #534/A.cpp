#include <cstdio>
using namespace std;

int main() {
	int N, i;
	scanf("%d", &N);
	for (i=9; i>=1; i--) {
		if (N % i == 0) break;
	}
	printf("%d\n", N/i);
	int cnt = N/i;
	while (cnt--) {
		printf("%d ", i);
	}
	puts("");
	return 0;
}