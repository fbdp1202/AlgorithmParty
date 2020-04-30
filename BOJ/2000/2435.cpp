// baekjoon 2435 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int N, K, ret;
int data[MAX_N];

int main()
{
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	int here = 0;
	for (int i=0; i<K; i++) {
		here += data[i];
	}
	ret = here;
	for (int i=K; i<N; i++) {
		here = here - data[i-K] + data[i];
		ret = max(ret, here);
	}
	printf("%d\n", ret);
	return 0;
}