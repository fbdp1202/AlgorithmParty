// baekjoon 2145 yechan
#include <cstdio>
#include <algorithm>
using namespace std;



int main()
{
	int N;
	while (1) {
		scanf("%d", &N);
		if (!N) break;
		int tmp;
		while (N >= 10) {
			tmp = N;
			N = 0;
			while (tmp) {
				N += tmp % 10;
				tmp /= 10;
			}
		}
		printf("%d\n", N);
	}
	return 0;
}