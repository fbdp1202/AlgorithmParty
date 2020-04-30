// baekjoon 10103 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int A=100, B=100;
	for (int i=0; i<N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < y) A-=y;
		if (x > y) B-=x;
	}
	printf("%d\n%d\n", A, B);
	return 0;
}
