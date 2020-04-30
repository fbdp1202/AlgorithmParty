// baekjoon 2553 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;

int main()
{
	scanf("%d", &N);
	int ret = 1;
	int count2 = 0, count5 = 0;
	int tmp;
	for (int i=1; i<=N; i++) {
		tmp = i;
		while (tmp % 10 == 0) tmp /= 10;
		while (tmp % 2 == 0) tmp /= 2, count2++;
		while (tmp % 5 == 0) tmp /= 5, count5++;

		ret *= tmp;
		ret %= 10;
	}
	count2 -= min(count2, count5);
	count5 -= min(count2, count5);
	while (count2--) {
		ret *= 2;
		ret %= 10;
	}
	while (count5--) {
		ret *= 5;
		ret %= 10;
	}
	printf("%d\n", ret);
	return 0;
}