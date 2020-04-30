// baekjoon 2693 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int A[10];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		for (int i=0; i<10; i++)
			scanf("%d", &A[i]);
		sort(A, A+10);
		printf("%d\n", A[7]);
	}
	return 0;
}