// baekjoon 2576 yechan
#include <cstdio>
#define INF 987654321
int main() {
	int minValue=INF, result=0, tmp;
	for (int i=0; i<7; i++) {
		scanf("%d", &tmp);
		if (tmp%2) {
			result+=tmp;
			if (minValue > tmp) {
				minValue=tmp;
			}
		}
	}
	if (minValue==INF) {
		puts("-1");
	}else {
		printf("%d\n%d",result, minValue);
	}
	return 0;
}