// baekjoon 2670 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
double data, ret=0, here=1.f;

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%lf", &data);
		ret = max(ret, data);
		ret = max(ret, data*here);
		if (here*data >= 1.f) {
			here *= data;
		} else {
			here = 1.f;
		}
	}
	printf("%.3lf\n", ret);
	return 0;
}