// baekjoon 5361 yechan
#include <cstdio>
int T, num;
float result, data[5] = {350.34, 230.90, 190.55, 125.30, 180.90};

int main() {
	scanf("%d", &T);
	for (int i=0; i<T; i++) {
		result=0;
		for (int j=0; j<5; j++) {
			scanf("%d", &num);
			result+=num*data[j];
		}
		printf("$%.2f\n", result);
	}
	return 0;
}