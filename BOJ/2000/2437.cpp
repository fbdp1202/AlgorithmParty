// baekjoon 2437 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001
int N, step, weight[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &weight[i]);
	}
	sort(weight, weight+N);
	for (int i=0; i<N; i++) {
		if (weight[i] <= step + 1) step += weight[i];
		else break;
	}
	printf("%d", step+1);
	return 0;
}