// baekjoon 2975 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	while (1)
	{
		int A, B;
		char c;
		scanf("%d %c %d", &A, &c, &B);
		if (!A && !B && c == 'W') break;

		if (c == 'W') A -= B;
		else A += B;

		if (A < -200) printf("Not allowed\n");
		else printf("%d\n", A);
	}
	return 0;
}