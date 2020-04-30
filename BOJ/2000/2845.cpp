// baekjoon 2845 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int L, P;
int N;

int main()
{
	scanf("%d%d", &L, &P);
	int ret = L * P;
	for (int i=0; i<5; i++) {
		scanf("%d", &N);
		printf("%d ", N-ret);
	}
	return 0;
}