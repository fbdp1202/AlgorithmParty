// baekjoon 5218 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char A[21], B[21];

int getDistance(char x, char y)
{
	if (x <= y) return y - x;
	return (y + 26) - x;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s%s", A, B);
		printf("Distances: ");
		for (int i=0; A[i]; i++) {
			printf("%d ", getDistance(A[i], B[i]));
		}
		puts("");
	}
	return 0;
}