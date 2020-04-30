// baekjoon 2566 yechan
#include <cstdio>
using namespace std;

int main() {
	int maxValue=0, maxIdx=0, tmp;
	for (int i=1; i<10; i++) {
		scanf("%d", &tmp);
		if (tmp > maxValue) {
			maxValue =tmp;
			maxIdx = i;
		}
	}
	printf("%d\n%d", maxValue, maxIdx);
	return 0;
}