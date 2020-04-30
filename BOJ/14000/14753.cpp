// baekjoon 14753 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=10001;
const int MIN_INF=-2e9;

int arr[MAX_N];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+N);
	int ret = MIN_INF;
	ret = max(ret, arr[0]*arr[1]*arr[N-1]);
	ret = max(ret, arr[N-1]*arr[N-2]*arr[N-3]);
	ret = max(ret, arr[0]*arr[1]);
	ret = max(ret, arr[N-1]*arr[N-2]);
	printf("%d\n", ret);
	return 0;
}