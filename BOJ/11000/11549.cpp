// baekjoon 11549 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int tea[6];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i=0; i<5; i++) {
		int x; scanf("%d", &x);
		tea[x]++;
	}
	printf("%d\n", tea[N]);
	return 0;
}