// baekjoon 1568 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int t = 0;
	int here = 1;
	while (N) {
		if (here <= N) {
			N -= here;
			here++;
		} else {
			here = 1;
			N -= here;
			here++;
		}
		t++;
	}
	printf("%d\n", t);

	return 0;
}