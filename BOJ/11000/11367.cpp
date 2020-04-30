// baekjoon 11367 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		char str[11];
		int N;
		scanf("%s %d", str, &N);
		printf("%s ", str);
		if (97 <= N) {
			printf("A+\n");
		} else if (90 <= N) {
			printf("A\n");
		} else if (87 <= N) {
			printf("B+\n");
		} else if (80 <= N) {
			printf("B\n");
		} else if (77 <= N) {
			printf("C+\n");
		} else if (70 <= N) {
			printf("C\n");
		} else if (67 <= N) {
			printf("D+\n");
		} else if (60 <= N) {
			printf("D\n");
		} else {
			printf("F\n");
		}
	}
	return 0;
}