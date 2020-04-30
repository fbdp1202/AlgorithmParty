// baekjoon 5086 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int A, B;
	while (1)
	{
		scanf("%d%d", &A, &B);
		if (A+B == 0) break;

		if (B % A == 0) {
			printf("factor\n");
			continue;
		}
		if (A % B == 0) {
			printf("multiple\n");
			continue;
		}
		printf("neither\n");
	}
	return 0;
}