// baekjoon 4101 yechan
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
	int A, B;
	while (1)
	{
		scanf("%d%d", &A, &B);
		if (!A && !B) break;
		puts(A>B ? "Yes" : "No");
	}

	return 0;
}