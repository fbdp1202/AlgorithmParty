// baekjoon 2566 yechan
#include <cstdio>
using namespace std;

int main() {
	int maxValue=0, maxIdx=0, maxJdx=0, tmp;
	for (int i=1; i<10; i++) {
		for (int j=1; j<10; j++) {
			scanf("%d", &tmp);
			if (tmp > maxValue) {
				maxValue =tmp;
				maxIdx = i;
				maxJdx = j;
			}
		}
	}
	printf("%d\n%d %d", maxValue, maxIdx, maxJdx);
	return 0;
}