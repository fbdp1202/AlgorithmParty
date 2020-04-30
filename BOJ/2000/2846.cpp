// baekjoon 2846 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int ret = 0;
	int prev=2e9, curr;
	int start = 2e9;
	for (int i=0; i<N; i++) {
		scanf("%d", &curr);
		if (prev < curr) {
			start = min(start, prev);
			ret = max(ret, curr - start);
		} else {
			start = 2e9;
		}
		prev = curr;
	}
	printf("%d\n", ret);
	return 0;
}