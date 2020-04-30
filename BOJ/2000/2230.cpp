// baekjoon 2230 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=100001;

int N, M, data[MAX_N], ret=2e9;

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%lld", &data[i]);
	sort(data, data+N);
	for (int i=0, j=0; i<N && j<N; ) {
		if (data[i] - data[j] >= M) {
			ret = min(ret, data[i]-data[j]);
			j++;
		} else {
			i++;
		}
	}
	printf("%d\n", ret);
	return 0;
}